.include "vm.i"
.include "data/game_globals.i"

.globl b_camera_shake_frames, _camera_shake_frames

.area _CODE_255

ACTOR = -4

___bank_script_s10t0_interact = 255
.globl ___bank_script_s10t0_interact

_script_s10t0_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0

        ; Actor Set Position
        VM_SET_CONST            ^/(ACTOR + 1)/, 6656
        VM_SET_CONST            ^/(ACTOR + 2)/, 1664
        VM_ACTOR_SET_POS        ACTOR

        ; Camera Shake
        VM_PUSH_CONST           6
        VM_PUSH_CONST           ^/(.CAMERA_SHAKE_X)/
        VM_INVOKE               b_camera_shake_frames, _camera_shake_frames, 2, .ARG1
        ; Stop Script
        VM_STOP
