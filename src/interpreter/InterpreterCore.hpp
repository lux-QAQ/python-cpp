#pragma once

// 不包含 vm/VM.hpp!
#include "forward.hpp"
#include "memory/GarbageCollector.hpp"
#include "runtime/forward.hpp"
#include "utilities.hpp"

#ifdef PYLANG_USE_ARENA
#include "memory/Arena.hpp"
#endif

#include <memory>
#include <string>
#include <string_view>
#include <vector>

class BytecodeProgram;
struct StackFrame;

// BaseException 前向声明（只用作指针参数，不需要完整定义）
namespace py {
class BaseException;
}

struct ScopedStack
{
	std::unique_ptr<StackFrame> top_frame;
	~ScopedStack();
	std::unique_ptr<StackFrame> release();
};

class Interpreter
	: NonCopyable
	, NonMoveable
{
  private:
	py::PyFrame *m_current_frame{ nullptr };
	py::PyFrame *m_global_frame{ nullptr };
	py::PyDict *m_modules{ nullptr };
	py::PyModule *m_module{ nullptr };
	py::PyModule *m_builtins{ nullptr };
	py::PyModule *m_importlib{ nullptr };
	py::PyObject *m_import_func{ nullptr };
	py::PyDict *m_codec_error_registry{ nullptr };
	py::PyList *m_codec_search_path{ nullptr };
	py::PyDict *m_codec_search_path_cache{ nullptr };
	std::string m_entry_script;
	std::vector<std::string> m_argv;

  public:
	struct Config
	{
		bool requires_importlib;
	};

	Interpreter();

	void raise_exception(py::BaseException *exception);

	py::PyFrame *execution_frame() const { return m_current_frame; }
	py::PyFrame *global_execution_frame() const { return m_global_frame; }
	void set_execution_frame(py::PyFrame *frame) { m_current_frame = frame; }

	[[nodiscard]] py::PyResult<std::monostate> store_object(const std::string &name,
		const py::Value &value);
	py::PyResult<py::Value> get_object(const std::string &name);

	template<typename PyObjectType, typename... Args>
	py::PyObject *allocate_object(const std::string &name, Args &&...args);

	py::PyModule *get_imported_module(py::PyString *) const;

	py::PyDict *modules() const { return m_modules; }
	py::PyModule *importlib() const { return m_importlib; }
	py::PyObject *importfunc() const { return m_import_func; }
	py::PyModule *builtins() const { return m_builtins; }
	py::PyModule *module() const { return m_module; }
	py::PyDict *codec_error_registry() { return m_codec_error_registry; }
	py::PyList *codec_search_path() { return m_codec_search_path; }
	py::PyDict *codec_search_path_cache() { return m_codec_search_path_cache; }
	const std::string &entry_script() const { return m_entry_script; }
	const std::vector<std::string> &argv() const { return m_argv; }

	void setup(std::shared_ptr<BytecodeProgram> &&program);
	void setup_main_interpreter(std::shared_ptr<BytecodeProgram> &&program);

	ScopedStack setup_call_stack(const std::unique_ptr<Function> &, py::PyFrame *function_frame);

	py::PyResult<py::PyObject *> call(const std::unique_ptr<Function> &,
		py::PyFrame *function_frame);
	py::PyResult<py::PyObject *>
		call(const std::unique_ptr<Function> &, py::PyFrame *function_frame, StackFrame &frame);
	py::PyResult<py::PyObject *>
		call(py::PyNativeFunction *native_func, py::PyTuple *args, py::PyDict *kwargs);
	py::PyResult<py::PyObject *> call(py::PyNativeFunction *native_func,
		py::PyObject *self,
		py::PyTuple *args,
		py::PyDict *kwargs);

	void visit_graph(::Cell::Visitor &);

  private:
	void internal_setup(const std::string &name,
		std::string entry_script,
		std::vector<std::string> argv,
		size_t local_registers,
		const py::PyTuple *consts,
		const std::vector<std::string> &names,
		Config &&,
		std::shared_ptr<Program> &&);
};

// void initialize_types();