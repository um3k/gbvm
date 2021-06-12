.include "vm.i"
.include "data/game_globals.i"

.globl b_camera_shake_frames, _camera_shake_frames

.area _CODE_255

___bank_script_s7_p_hit1 = 255
.globl ___bank_script_s7_p_hit1

_script_s7_p_hit1::
        ; Camera Shake
        VM_PUSH_CONST           30
        VM_PUSH_CONST           ^/(.CAMERA_SHAKE_X)/
        VM_INVOKE               b_camera_shake_frames, _camera_shake_frames, 2, .ARG1
        ; Stop Script
        VM_STOP
