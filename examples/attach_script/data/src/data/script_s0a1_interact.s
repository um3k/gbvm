.module script_s0a1_interact

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255


___bank_script_s0a1_interact = 255
.globl ___bank_script_s0a1_interact
.CURRENT_SCRIPT_BANK == ___bank_script_s0a1_interact

_script_s0a1_interact::
        VM_LOCK

        ; Input Script Remove
        VM_INPUT_DETACH         16

        ; Stop Script
        VM_STOP
