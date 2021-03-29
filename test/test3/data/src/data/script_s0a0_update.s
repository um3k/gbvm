.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s0a0_update = 255
.globl ___bank_script_s0a0_update

_script_s0a0_update::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_RIGHT

        ; Wait N Frames
        VM_PUSH_CONST           6
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_LEFT

        ; Wait N Frames
        VM_PUSH_CONST           6
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
