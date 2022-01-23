.module script_enemy_ship_hit_player

.include "vm.i"
.include "data/game_globals.i"

.globl b_camera_shake_frames, _camera_shake_frames

.area _CODE_255


___bank_script_enemy_ship_hit_player = 255
.globl ___bank_script_enemy_ship_hit_player
.CURRENT_SCRIPT_BANK == ___bank_script_enemy_ship_hit_player

_script_enemy_ship_hit_player::
        ; Camera Shake
        VM_PUSH_CONST           30
        VM_PUSH_CONST           .CAMERA_SHAKE_X
        VM_INVOKE               b_camera_shake_frames, _camera_shake_frames, 2, .ARG1
        ; Sound Play Crash
        VM_SOUND_PLAY           30, 4, 0x01, 0xF2, 0x13, 0x80, 0x00
        VM_RET_FAR
