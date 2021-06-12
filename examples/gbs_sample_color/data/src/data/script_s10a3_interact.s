.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_s10a3_interact = 255
.globl ___bank_script_s10a3_interact

_script_s10a3_interact::
        ; Call Script: Turnip Collisions
        VM_PUSH_CONST           4 ; Actor .ARG4
        VM_PUSH_CONST           VAR_TURNIP_COUNTER ; Variable .ARG3
        VM_PUSH_CONST           VAR_S10A10_DEFEATED_1 ; Variable .ARG2
        VM_CALL_FAR             ___bank_script_turnip_collisions, _script_turnip_collisions
        VM_POP                  3

        ; Stop Script
        VM_STOP
