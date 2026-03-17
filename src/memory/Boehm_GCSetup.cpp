#include <cstdio>
#include <cstring>

#ifdef PYLANG_USE_Boehm_GC
#include <gc.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#pragma GCC diagnostic ignored "-Wformat-security"

void pylang_gc_warn_proc(char *msg, GC_word arg)
{
    // _no_order 不再产生 Finalization cycle 警告
    // 但保留过滤以防万一
    if (msg && strstr(msg, "Finalization cycle") != nullptr) { return; }
    fprintf(stderr, msg, static_cast<unsigned long>(arg));
}

#pragma GCC diagnostic pop

#endif