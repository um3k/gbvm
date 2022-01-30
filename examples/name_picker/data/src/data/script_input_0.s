.module script_input_0

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

.LOCAL_TMP0_WAIT_ARGS = -1

___bank_script_input_0 = 255
.globl ___bank_script_input_0

_script_input_0::
        VM_RESERVE              1

        ; If Variable .GT Value
        VM_IF_CONST .GT         VAR_STRING_INDEX, 0, 1$, 0
        VM_JUMP                 2$
1$:
        ; Variable Decrement By 1
        VM_RPN
            .R_REF      VAR_STRING_INDEX
            .R_INT8     1
            .R_OPERATOR .SUB
            .R_STOP
        VM_SET                  VAR_STRING_INDEX, .ARG0
        VM_POP                  1

2$:

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 5

4$:
        ; If Variable .GT Variable
        VM_IF .GT               VAR_TEMP_0, VAR_STRING_INDEX, 5$, 0
        ; Call Script: Update Input Fields
        VM_CALL_FAR             ___bank_script_update_input_fields, _script_update_input_fields

        VM_JUMP                 7$
        VM_JUMP                 6$
5$:
        ; Variable Decrement By 1
        VM_RPN
            .R_REF      VAR_TEMP_0
            .R_INT8     1
            .R_OPERATOR .SUB
            .R_STOP
        VM_SET                  VAR_TEMP_0, .ARG0
        VM_POP                  1

        ; Switch Variable
        VM_SWITCH               VAR_TEMP_0, 5, 0
        .dw 0, 8$
        .dw 1, 9$
        .dw 2, 10$
        .dw 3, 11$
        .dw 4, 12$

        ; Variable Set To Value
        VM_SET_CONST            VAR_STRING_INDEX, 4

        VM_JUMP                 13$
        ; case 0:
8$:
        ; Variable Set To Value
        VM_SET_CONST            VAR_STRING_0_, 1

        VM_JUMP                 13$
        ; case 1:
9$:
        ; Variable Set To Value
        VM_SET_CONST            VAR_STRING_1_, 1

        VM_JUMP                 13$
        ; case 2:
10$:
        ; Variable Set To Value
        VM_SET_CONST            VAR_STRING_2_, 1

        VM_JUMP                 13$
        ; case 3:
11$:
        ; Variable Set To Value
        VM_SET_CONST            VAR_STRING_3_, 1

        VM_JUMP                 13$
        ; case 4:
12$:
        ; Variable Set To Value
        VM_SET_CONST            VAR_STRING_4_, 1

        VM_JUMP                 13$
13$:

6$:

        VM_JUMP                 4$
7$:
        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP0_WAIT_ARGS, 12
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP0_WAIT_ARGS

        ; Stop Script
        VM_STOP
