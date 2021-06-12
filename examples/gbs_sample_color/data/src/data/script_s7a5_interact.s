.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_s7a5_interact = 255
.globl ___bank_script_s7a5_interact

_script_s7a5_interact::
        ; Call Script: Enemy Ship Hit Player
        VM_CALL_FAR             ___bank_script_enemy_ship_hit_player, _script_enemy_ship_hit_player

        ; Stop Script
        VM_STOP
