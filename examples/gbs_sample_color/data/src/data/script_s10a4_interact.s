.module script_s10a4_interact

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255


___bank_script_s10a4_interact = 255
.globl ___bank_script_s10a4_interact
.CURRENT_SCRIPT_BANK == ___bank_script_s10a4_interact

_script_s10a4_interact::
        ; If Parameter 0 Equals 0
        VM_PUSH_CONST           0
        VM_GET_TLOCAL           .ARG0, 0
        VM_IF_CONST .EQ         .ARG0, 0, 1$, 1
        VM_JUMP                 2$
1$:
        ; Call Script: Turnip Collisions
        VM_PUSH_CONST           5 ; Actor .ARG4
        VM_PUSH_CONST           VAR_TURNIP_COUNTER ; Variable .ARG3
        VM_PUSH_CONST           VAR_S10A10_DEFEATED_2 ; Variable .ARG2
        VM_CALL_FAR             ___bank_script_turnip_collisions, _script_turnip_collisions
        VM_POP                  3

        ; Stop Script
        VM_STOP
2$:

        ; Stop Script
        VM_STOP
