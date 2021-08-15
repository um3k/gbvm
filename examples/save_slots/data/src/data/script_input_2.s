.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_input_2 = 255
.globl ___bank_script_input_2

_script_input_2::
        ; Variable Increment By 1
        VM_RPN
            .R_REF      VAR_S1_MONEY
            .R_INT8     1
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  VAR_S1_MONEY, .ARG0
        VM_POP                  1

        ; Stop Script
        VM_STOP
