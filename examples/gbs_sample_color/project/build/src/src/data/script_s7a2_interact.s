.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_s7a2_interact = 255
.globl ___bank_script_s7a2_interact

_script_s7a2_interact::
        ; Call Script: Enemy Ship Hit Player
        VM_CALL_FAR             ___bank_script_custom_2, _script_custom_2

        ; Stop Script
        VM_STOP
