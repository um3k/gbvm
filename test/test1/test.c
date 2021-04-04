#include <gb/gb.h>
#include <stdio.h>
#include <string.h>

#include "framework/test_main.h"

void core_reset_hook() {}

void test() {
    printf("hello, world!");
    strcpy(result, "PASSED"); 
    delay(100);
}
