.module script_s0a0_interact

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255


___bank_script_s0a0_interact = 255
.globl ___bank_script_s0a0_interact

_script_s0a0_interact::
        VM_LOCK

        ; Input Script Attach
        VM_CONTEXT_PREPARE      4, ___bank_script_input_0, _script_input_0
        VM_INPUT_ATTACH         16, ^/(4 | .OVERRIDE_DEFAULT)/

        ; Stop Script
        VM_STOP
