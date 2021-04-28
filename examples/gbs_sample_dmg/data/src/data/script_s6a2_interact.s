.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s6a2_interact = 255
.globl ___bank_script_s6a2_interact

_script_s6a2_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 3
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Push
        VM_SET_CONST            ACTOR, 0
        VM_PUSH_CONST           0
        VM_ACTOR_GET_DIR        ^/(ACTOR - 1)/, .ARG0
        VM_SET_CONST            ^/(ACTOR - 1)/, 3
        VM_ACTOR_GET_POS        ^/(ACTOR - 1)/
        VM_IF_CONST .EQ         .ARG0, .DIR_UP, 1$, 0
        VM_IF_CONST .EQ         .ARG0, .DIR_LEFT, 2$, 0
        VM_IF_CONST .EQ         .ARG0, .DIR_RIGHT, 3$, 0
        VM_RPN
            .R_REF      ^/(ACTOR + 2 - 1)/
            .R_INT16    256
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  1
        VM_JUMP                 4$
1$:
        VM_RPN
            .R_REF      ^/(ACTOR + 2 - 1)/
            .R_INT16    256
            .R_OPERATOR .SUB
            .R_INT16    0
            .R_OPERATOR .MAX
            .R_STOP
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  1
        VM_JUMP                 4$
2$:
        VM_RPN
            .R_REF      ^/(ACTOR + 1 - 1)/
            .R_INT16    256
            .R_OPERATOR .SUB
            .R_INT16    0
            .R_OPERATOR .MAX
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG0
        VM_POP                  1
        VM_JUMP                 4$
3$:
        VM_RPN
            .R_REF      ^/(ACTOR + 1 - 1)/
            .R_INT16    256
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG0
        VM_POP                  1
4$:
        VM_POP                  1
        VM_SET_CONST            ^/(ACTOR + 3)/, .ACTOR_ATTR_CHECK_COLL
        VM_ACTOR_MOVE_TO        ACTOR

        ; Stop Script
        VM_STOP
