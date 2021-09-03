.include "vm.i"
.include "data/game_globals.i"

.globl b_camera_shake_frames, _camera_shake_frames

.area _CODE_255


___bank_script_s7_p_hit1 = 255
.globl ___bank_script_s7_p_hit1

_script_s7_p_hit1::
        ; If Parameter 0 Equals 2
        VM_PUSH_CONST           0
        VM_GET_TLOCAL           .ARG0, 0
        VM_IF_CONST .EQ         .ARG0, 2, 1$, 1
        VM_JUMP                 2$
1$:
        ; Camera Shake
        VM_PUSH_CONST           30
        VM_PUSH_CONST           ^/(.CAMERA_SHAKE_X)/
        VM_INVOKE               b_camera_shake_frames, _camera_shake_frames, 2, .ARG1
        ; Stop Script
        VM_STOP
2$:

        ; If Parameter 0 Equals 4
        VM_PUSH_CONST           0
        VM_GET_TLOCAL           .ARG0, 0
        VM_IF_CONST .EQ         .ARG0, 4, 3$, 1
        VM_JUMP                 4$
3$:
        ; Camera Shake
        VM_PUSH_CONST           30
        VM_PUSH_CONST           ^/(.CAMERA_SHAKE_X)/
        VM_INVOKE               b_camera_shake_frames, _camera_shake_frames, 2, .ARG1
        ; Stop Script
        VM_STOP
4$:

        ; If Parameter 0 Equals 8
        VM_PUSH_CONST           0
        VM_GET_TLOCAL           .ARG0, 0
        VM_IF_CONST .EQ         .ARG0, 8, 5$, 1
        VM_JUMP                 6$
5$:
        ; Camera Shake
        VM_PUSH_CONST           30
        VM_PUSH_CONST           ^/(.CAMERA_SHAKE_X)/
        VM_INVOKE               b_camera_shake_frames, _camera_shake_frames, 2, .ARG1
        ; Stop Script
        VM_STOP
6$:

        ; Stop Script
        VM_STOP
