.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s0_init = 255
.globl ___bank_script_s0_init

_script_s0_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 256
        VM_SET_CONST            ^/(ACTOR + 2)/, 896
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        ACTOR

        ; Stop Script
        VM_STOP
