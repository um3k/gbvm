.include "vm.i"
.include "data/game_globals.i"

.globl b_camera_shake_frames, _camera_shake_frames

.area _CODE_255



___bank_script_custom_2 = 255
.globl ___bank_script_custom_2

_script_custom_2::
        ; Camera Shake
        VM_PUSH_CONST           30
        VM_PUSH_CONST           ^/(.CAMERA_SHAKE_X)/
        VM_INVOKE               b_camera_shake_frames, _camera_shake_frames, 2, .ARG1
        VM_RET_FAR
