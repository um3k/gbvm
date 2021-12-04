.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s7a0_update = 255
.globl ___bank_script_s7a0_update

_script_s7a0_update::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

2$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 1024
        VM_SET_CONST            ^/(ACTOR + 2)/, 1280
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        ACTOR

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 1024
        VM_SET_CONST            ^/(ACTOR + 2)/, 2176
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        ACTOR

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 256
        VM_SET_CONST            ^/(ACTOR + 2)/, 2176
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        ACTOR

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 256
        VM_SET_CONST            ^/(ACTOR + 2)/, 1280
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        ACTOR

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        VM_JUMP                 2$
        ; Stop Script
        VM_STOP
