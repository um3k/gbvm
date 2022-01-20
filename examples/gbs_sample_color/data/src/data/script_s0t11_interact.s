.module script_s0t11_interact

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s0t11_interact = 255
.globl ___bank_script_s0t11_interact
.CURRENT_SCRIPT_BANK == ___bank_script_s0t11_interact

_script_s0t11_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST11, 0, 1$, 0
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 8

        ; If Actor At Position
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    4608
            .R_OPERATOR .EQ
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    3072
            .R_OPERATOR .EQ
            .R_OPERATOR .AND
            .R_STOP
        VM_IF_CONST .EQ         .ARG0, 0, 3$, 1
        VM_JUMP                 4$
3$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 8

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_DOWN

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 8

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 8

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 5632
        VM_SET_CONST            ^/(ACTOR + 2)/, 2432
        VM_SET_CONST            ^/(ACTOR + 3)/, 0
        VM_ACTOR_MOVE_TO        ACTOR

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 8

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 4864
        VM_SET_CONST            ^/(ACTOR + 2)/, 2688
        VM_SET_CONST            ^/(ACTOR + 3)/, .ACTOR_ATTR_H_FIRST
        VM_ACTOR_MOVE_TO        ACTOR

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 8

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 4608
        VM_SET_CONST            ^/(ACTOR + 2)/, 3072
        VM_SET_CONST            ^/(ACTOR + 3)/, .ACTOR_ATTR_H_FIRST
        VM_ACTOR_MOVE_TO        ACTOR

4$:

        VM_JUMP                 2$
1$:
2$:

        ; Stop Script
        VM_STOP
