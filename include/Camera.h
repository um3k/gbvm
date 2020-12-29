#ifndef CAMERA_H
#define CAMERA_H

#include <gb/gb.h>

#define CAMERA_LOCK_FLAG 0x1

extern INT16 camera_x;
extern INT16 camera_y;
extern BYTE camera_offset_x;
extern BYTE camera_offset_y;
extern BYTE camera_deadzone_x;
extern BYTE camera_deadzone_y;
extern UBYTE camera_settings;

void camera_init() __banked;
void camera_update() __banked;

#endif