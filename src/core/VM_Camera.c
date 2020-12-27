#pragma bank 2

#include "vm.h"

#include "Camera.h"
#include "GameTime.h"

typedef struct cam_move_to_t {
    INT16 X, Y;
    UBYTE speed;
} cam_move_to_t;

void vm_camera_move_to(SCRIPT_CTX * THIS, INT16 idx) __banked {

    // indicate waitable state of context
    THIS->waitable = 1;

    cam_move_to_t * params = VM_REF_TO_PTR(idx);

    // Actor reached destination
    if ((camera_x == params->X) && (camera_y == params->Y)) {
        // if (after_lock_camera) {
        //     camera_settings = camera_settings | CAMERA_LOCK_FLAG;
        // }
        return;
    }

    // Move camera towards destination
    if ((game_time & params->speed) == 0) {
        if (camera_x > params->X) {
            camera_x--;
        } else if (camera_x < params->X) {
            camera_x++;
        }
        if (camera_y > params->Y) {
            camera_y--;
        } else if (camera_y < params->Y) {
            camera_y++;
        }
    }

    THIS->PC -= (INSTRUCTION_SIZE + sizeof(idx));
    return;
}
