.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255


___bank_script_s7a8_hit1 = 255
.globl ___bank_script_s7a8_hit1

_script_s7a8_hit1::
        ; If Parameter 0 Equals 2
        VM_PUSH_CONST           0
        VM_GET_TLOCAL           .ARG0, 0
        VM_IF_CONST .EQ         .ARG0, 2, 1$, 1
        VM_JUMP                 2$
1$:
        ; Call Script: Enemy Ship Destroy
        VM_PUSH_CONST           9 ; Actor .ARG2
        VM_CALL_FAR             ___bank_script_enemy_ship_destroy, _script_enemy_ship_destroy
        VM_POP                  1

        ; Stop Script
        VM_STOP
2$:

        ; Stop Script
        VM_STOP
