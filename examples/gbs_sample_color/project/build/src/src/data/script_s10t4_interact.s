.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_s10t4_interact = 255
.globl ___bank_script_s10t4_interact

_script_s10t4_interact::
        VM_LOCK

        ; Stop Script
        VM_STOP
