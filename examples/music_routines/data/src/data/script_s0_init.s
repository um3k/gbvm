.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255



___bank_script_s0_init = 255
.globl ___bank_script_s0_init

_script_s0_init::
        VM_LOCK

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "\001\001Hello\n\002\002world"
        VM_OVERLAY_CLEAR        0, 0, 20, 6, .UI_COLOR_WHITE, .UI_DRAW_FRAME
        VM_OVERLAY_MOVE_TO      0, 12, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Set Music Routine
        VM_MUSIC_ROUTINE        0, ___bank_script_music_routine_0, _script_music_routine_0

        ; Set Music Routine
        VM_MUSIC_ROUTINE        1, ___bank_script_music_routine_1, _script_music_routine_1

        ; Set Music Routine
        VM_MUSIC_ROUTINE        2, ___bank_script_music_routine_2, _script_music_routine_2

        ; Set Music Routine
        VM_MUSIC_ROUTINE        3, ___bank_script_music_routine_3, _script_music_routine_3

        ; Music Play
        VM_MUSIC_PLAY           ___bank_music_track_0__Data, _music_track_0__Data, .MUSIC_LOOP

        ; Stop Script
        VM_STOP
