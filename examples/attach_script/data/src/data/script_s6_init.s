.module script_s6_init

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255


___bank_script_s6_init = 255
.globl ___bank_script_s6_init

_script_s6_init::
        VM_LOCK

        ; Music Play
        VM_MUSIC_PLAY           ___bank_music_track_0__Data, _music_track_0__Data, .MUSIC_LOOP

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Mute Channel
        VM_MUSIC_MUTE      ^/(0x0f & 0x0e & 0x0b)/

        ; Stop Script
        VM_STOP
