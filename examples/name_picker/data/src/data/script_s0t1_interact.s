.module script_s0t1_interact

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s0t1_interact = 255
.globl ___bank_script_s0t1_interact
.CURRENT_SCRIPT_BANK == ___bank_script_s0t1_interact

_script_s0t1_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0

        ; Store Position In Variables
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    128
            .R_OPERATOR .DIV
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    128
            .R_OPERATOR .DIV
            .R_STOP
        VM_SET                  VAR_TEMP_0, .ARG1
        VM_SET                  VAR_TEMP_1, .ARG0
        VM_POP                  2

        ; Variables .SUB Value
        VM_RPN
            .R_REF      VAR_TEMP_0
            .R_INT16    11
            .R_OPERATOR .SUB
            .R_STOP
        VM_SET                  VAR_TEMP_0, .ARG0
        VM_POP                  1

        ; Variables .SUB Value
        VM_RPN
            .R_REF      VAR_TEMP_1
            .R_INT16    2
            .R_OPERATOR .SUB
            .R_STOP
        VM_SET                  VAR_TEMP_1, .ARG0
        VM_POP                  1

        ; Variables .DIV Value
        VM_RPN
            .R_REF      VAR_TEMP_1
            .R_INT16    2
            .R_OPERATOR .DIV
            .R_STOP
        VM_SET                  VAR_TEMP_1, .ARG0
        VM_POP                  1

        ; Variable Set To Value
        VM_SET_CONST            VAR_S0T1_LOCAL_0, 7

        ; Variables .MUL
        VM_RPN
            .R_REF      VAR_S0T1_LOCAL_0
            .R_REF      VAR_TEMP_1
            .R_OPERATOR .MUL
            .R_STOP
        VM_SET                  VAR_S0T1_LOCAL_0, .ARG0
        VM_POP                  1

        ; Variables .ADD
        VM_RPN
            .R_REF      VAR_S0T1_LOCAL_0
            .R_REF      VAR_TEMP_0
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  VAR_S0T1_LOCAL_0, .ARG0
        VM_POP                  1

        ; If Variable .LT Value
        VM_IF_CONST .LT         VAR_S0T1_LOCAL_0, 26, 1$, 0
        VM_JUMP                 2$
1$:
        ; Variables .ADD Value
        VM_RPN
            .R_REF      VAR_S0T1_LOCAL_0
            .R_INT16    35
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  VAR_S0T1_LOCAL_0, .ARG0
        VM_POP                  1

        ; Switch Variable
        ; case 0:
        VM_IF_CONST .NE         VAR_STRING_INDEX, 0, 3$, 0
        ; Variable Copy
        VM_SET                  VAR_STRING_0_, VAR_S0T1_LOCAL_0

        VM_JUMP                 8$
3$:
        ; case 1:
        VM_IF_CONST .NE         VAR_STRING_INDEX, 1, 4$, 0
        ; Variable Copy
        VM_SET                  VAR_STRING_1_, VAR_S0T1_LOCAL_0

        VM_JUMP                 8$
4$:
        ; case 2:
        VM_IF_CONST .NE         VAR_STRING_INDEX, 2, 5$, 0
        ; Variable Copy
        VM_SET                  VAR_STRING_2_, VAR_S0T1_LOCAL_0

        VM_JUMP                 8$
5$:
        ; case 3:
        VM_IF_CONST .NE         VAR_STRING_INDEX, 3, 6$, 0
        ; Variable Copy
        VM_SET                  VAR_STRING_3_, VAR_S0T1_LOCAL_0

        VM_JUMP                 8$
6$:
        ; case 4:
        VM_IF_CONST .NE         VAR_STRING_INDEX, 4, 7$, 0
        ; Variable Copy
        VM_SET                  VAR_STRING_4_, VAR_S0T1_LOCAL_0

        VM_JUMP                 8$
7$:
        ; default:
        ; Variable Copy
        VM_SET                  VAR_STRING_4_, VAR_S0T1_LOCAL_0

8$:

        ; If Variable .LT Value
        VM_IF_CONST .LT         VAR_STRING_INDEX, 5, 9$, 0
        VM_JUMP                 10$
9$:
        ; Variable Increment By 1
        VM_RPN
            .R_REF      VAR_STRING_INDEX
            .R_INT8     1
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  VAR_STRING_INDEX, .ARG0
        VM_POP                  1

10$:

2$:

        ; Call Script: Update Input Fields
        VM_CALL_FAR             ___bank_script_update_input_fields, _script_update_input_fields

        ; Stop Script
        VM_STOP
