#include "runtime/KeyVersionTracker.hpp"

#include <gtest/gtest.h>
#include <thread>
#include <vector>

using namespace py;

// =============================================================================
// KeyVersionTracker 基础测试
// =============================================================================

TEST(KeyVersionTracker, InitialVersionIsZero)
{
	KeyVersionTracker tracker;
	EXPECT_EQ(tracker.get("nonexistent"), 0u);
	EXPECT_EQ(tracker.get("x"), 0u);
	EXPECT_EQ(tracker.get(""), 0u);
}

TEST(KeyVersionTracker, BumpCreatesEntry)
{
	KeyVersionTracker tracker;
	EXPECT_FALSE(tracker.contains("x"));
	tracker.bump("x");
	EXPECT_TRUE(tracker.contains("x"));
	EXPECT_EQ(tracker.get("x"), 1u);
}

TEST(KeyVersionTracker, BumpIncrementsVersion)
{
	KeyVersionTracker tracker;
	tracker.bump("x");
	EXPECT_EQ(tracker.get("x"), 1u);
	tracker.bump("x");
	EXPECT_EQ(tracker.get("x"), 2u);
	tracker.bump("x");
	EXPECT_EQ(tracker.get("x"), 3u);
}

TEST(KeyVersionTracker, IndependentKeys)
{
	KeyVersionTracker tracker;
	tracker.bump("x");
	tracker.bump("x");
	tracker.bump("x");
	tracker.bump("y");

	EXPECT_EQ(tracker.get("x"), 3u);
	EXPECT_EQ(tracker.get("y"), 1u);
	EXPECT_EQ(tracker.get("z"), 0u);
}

TEST(KeyVersionTracker, NoCacheThrashing)
{
	// 核心场景：修改 "counter" 不影响 "pi" 的版本号
	KeyVersionTracker tracker;
	tracker.bump("pi");
	uint64_t pi_version = tracker.get("pi");

	for (int i = 0; i < 10000; ++i) { tracker.bump("counter"); }

	// pi 的版本号不应变化
	EXPECT_EQ(tracker.get("pi"), pi_version);
	EXPECT_EQ(tracker.get("counter"), 10000u);
}

TEST(KeyVersionTracker, EmptyKeyName)
{
	KeyVersionTracker tracker;
	tracker.bump("");
	EXPECT_EQ(tracker.get(""), 1u);
	EXPECT_TRUE(tracker.contains(""));
}

TEST(KeyVersionTracker, SpecialCharacterKeys)
{
	KeyVersionTracker tracker;
	tracker.bump("__name__");
	tracker.bump("__init__");
	tracker.bump("foo.bar");
	EXPECT_EQ(tracker.get("__name__"), 1u);
	EXPECT_EQ(tracker.get("__init__"), 1u);
	EXPECT_EQ(tracker.get("foo.bar"), 1u);
}

TEST(KeyVersionTracker, ManyKeys)
{
	KeyVersionTracker tracker;
	constexpr int N = 1000;
	for (int i = 0; i < N; ++i) { tracker.bump("key_" + std::to_string(i)); }
	for (int i = 0; i < N; ++i) { EXPECT_EQ(tracker.get("key_" + std::to_string(i)), 1u); }
}

TEST(KeyVersionTracker, MultiThreadBump)
{
	KeyVersionTracker tracker;
	constexpr int per_thread = 10000;
	constexpr int num_threads = 4;

	std::vector<std::thread> threads;
	for (int t = 0; t < num_threads; ++t) {
		threads.emplace_back([&tracker]() {
			for (int i = 0; i < per_thread; ++i) { tracker.bump("shared_key"); }
		});
	}
	for (auto &t : threads) { t.join(); }

	EXPECT_EQ(tracker.get("shared_key"), static_cast<uint64_t>(per_thread * num_threads));
}

TEST(KeyVersionTracker, MultiThreadIndependentKeys)
{
	KeyVersionTracker tracker;
	constexpr int per_thread = 5000;

	std::thread t1([&]() {
		for (int i = 0; i < per_thread; ++i) { tracker.bump("key_a"); }
	});
	std::thread t2([&]() {
		for (int i = 0; i < per_thread; ++i) { tracker.bump("key_b"); }
	});

	t1.join();
	t2.join();

	EXPECT_EQ(tracker.get("key_a"), static_cast<uint64_t>(per_thread));
	EXPECT_EQ(tracker.get("key_b"), static_cast<uint64_t>(per_thread));
}