.module script_s10a3_interact

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

.LOCAL_TMP0_PARAM0_VALUE = -1

___bank_script_s10a3_interact = 255
.globl ___bank_script_s10a3_interact

_script_s10a3_interact::
        VM_RESERVE              1

        ; If Parameter 0 Equals 0
        VM_GET_TLOCAL           .LOCAL_TMP0_PARAM0_VALUE, 0
        VM_IF_CONST .EQ         .LOCAL_TMP0_PARAM0_VALUE, 0, 1$, 0
        VM_JUMP                 2$
1$:
        ; Call Script: Turnip Collisions
        VM_PUSH_CONST           4 ; Actor SCRIPT_ARG_2_ACTOR
        VM_PUSH_CONST           VAR_TURNIP_COUNTER ; Variable SCRIPT_ARG_1_VARIABLE
        VM_PUSH_CONST           VAR_S10A10_DEFEATED_1 ; Variable SCRIPT_ARG_0_VARIABLE
        VM_CALL_FAR             ___bank_script_turnip_collisions, _script_turnip_collisions

        ; Stop Script
        VM_STOP
2$:

        ; Stop Script
        VM_STOP
