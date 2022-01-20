.module script_s12a1_update

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s12a1_update = 255
.globl ___bank_script_s12a1_update
.CURRENT_SCRIPT_BANK == ___bank_script_s12a1_update

_script_s12a1_update::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 1024
        VM_SET_CONST            ^/(ACTOR + 2)/, 1536
        VM_SET_CONST            ^/(ACTOR + 3)/, 0
        VM_ACTOR_MOVE_TO        ACTOR

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_UP

        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 768
        VM_SET_CONST            ^/(ACTOR + 2)/, 1536
        VM_SET_CONST            ^/(ACTOR + 3)/, .ACTOR_ATTR_H_FIRST
        VM_ACTOR_MOVE_TO        ACTOR

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_UP

        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 512
        VM_SET_CONST            ^/(ACTOR + 2)/, 1280
        VM_SET_CONST            ^/(ACTOR + 3)/, .ACTOR_ATTR_H_FIRST
        VM_ACTOR_MOVE_TO        ACTOR

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_UP

        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 1024
        VM_SET_CONST            ^/(ACTOR + 2)/, 1536
        VM_SET_CONST            ^/(ACTOR + 3)/, 0
        VM_ACTOR_MOVE_TO        ACTOR

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
