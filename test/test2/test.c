#include "core.h"
#include "test_main.h"

void core_reset_hook() {
    core_reset();
}

void test() {
    core_run();
}
