.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_s7a9_hit1 = 255
.globl ___bank_script_s7a9_hit1

_script_s7a9_hit1::
        ; Call Script: Enemy Ship Destroy
        VM_PUSH_CONST           10 ; Actor .ARG2
        VM_CALL_FAR             ___bank_script_enemy_ship_destroy, _script_enemy_ship_destroy
        VM_POP                  1

        ; Stop Script
        VM_STOP
