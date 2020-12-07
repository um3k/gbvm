#ifndef UI_H
#define UI_H

#include <gb/gb.h>

#define TEXT_BUFFER_START 0xCCU

void init_ui() __nonbanked;
void update_ui() __banked;

#endif
