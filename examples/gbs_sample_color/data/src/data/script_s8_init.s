.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s8_init = 255
.globl ___bank_script_s8_init

_script_s8_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Call Script: Init Menu
        VM_CALL_FAR             ___bank_script_custom_0, _script_custom_0

        ; Music Play
        VM_MUSIC_PLAY           ___bank_music_track_3__Data, _music_track_3__Data, .MUSIC_LOOP

        ; Player Set Spritesheet
        VM_SET_CONST            ACTOR, 0
        VM_ACTOR_SET_SPRITESHEET ACTOR, ___bank_spritesheet_5, _spritesheet_5

        ; Stop Script
        VM_STOP
