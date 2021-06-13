.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

___bank_script_s9_init = 255
.globl ___bank_script_s9_init

_script_s9_init::
        VM_LOCK

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Music Routine Attach
        VM_MUSIC_ROUTINE        0, ___bank_script_music_0, _script_music_0

        ; Music Routine Attach
        VM_MUSIC_ROUTINE        1, ___bank_script_music_0, _script_music_0

        ; Music Routine Attach
        VM_MUSIC_ROUTINE        2, ___bank_script_music_0, _script_music_0

        ; Music Routine Attach
        VM_MUSIC_ROUTINE        3, ___bank_script_music_0, _script_music_0

        ; Music Play
        VM_MUSIC_PLAY           ___bank_music_track_1__Data, _music_track_1__Data, .MUSIC_LOOP

        ; Stop Script
        VM_STOP
