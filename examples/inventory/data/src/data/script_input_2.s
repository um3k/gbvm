.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_input_2 = 255
.globl ___bank_script_input_2

_script_input_2::
        ; Call Script: 
        VM_PUSH_CONST           VAR_VARIABLE_100 ; Variable .ARG2
        VM_CALL_FAR             ___bank_script_custom_0, _script_custom_0
        VM_POP                  1

        ; Stop Script
        VM_STOP
