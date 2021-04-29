.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_s10a1_interact = 255
.globl ___bank_script_s10a1_interact

_script_s10a1_interact::
        ; Call Script: Turnip Collisions
        VM_PUSH_CONST           0 ; Actor .ARG4
        VM_PUSH_CONST           VAR_TURNIP_COUNTER ; Variable .ARG3
        VM_PUSH_CONST           VAR_S10A10_DEFEATED ; Variable .ARG2
        VM_CALL_FAR             ___bank_script_custom_9, _script_custom_9
        VM_POP                  3

        ; Stop Script
        VM_STOP
