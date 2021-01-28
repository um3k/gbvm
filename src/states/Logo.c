#pragma bank 3

#include "states/Logo.h"

#include "Camera.h"
#include "GameTime.h"

void logo_init() __banked {
  camera_offset_x = 0;
  camera_offset_y = 0;

  game_time = 0;
}

void logo_update() __banked {
    return;
}
