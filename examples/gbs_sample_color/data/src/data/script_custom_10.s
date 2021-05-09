.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_custom_10 = 255
.globl ___bank_script_custom_10

_script_custom_10::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0

        ; If Actor Relative To Actor
        VM_ACTOR_GET_POS        ACTOR
        VM_PUSH_VALUE           ^/(.ARG2 - 4)/
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_ACTOR_GET_POS        .ARG2
        VM_RPN
            .R_REF      ^/(ACTOR + 1 - 3)/
            .R_REF      .ARG1
            .R_OPERATOR .LT
            .R_STOP
        VM_IF_CONST .EQ         .ARG0, 0, 1$, 4
        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG2 - 4)/

        ; Actor Move Relative
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    -512
            .R_OPERATOR .ADD
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    0
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        ACTOR

        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG2 - 4)/

        ; Actor Move Relative
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    512
            .R_OPERATOR .ADD
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    0
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        ACTOR

2$:

        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        VM_POP                  4
        VM_RET_FAR
