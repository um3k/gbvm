.module script_s1_init

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames, _fade_frames_per_step

.area _CODE_255

ACTOR = -4

___bank_script_s1_init = 255
.globl ___bank_script_s1_init
.CURRENT_SCRIPT_BANK == ___bank_script_s1_init

_script_s1_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Hide
        VM_SET_CONST            ACTOR, 0
        VM_ACTOR_SET_HIDDEN     ACTOR, 1
        VM_ACTOR_DEACTIVATE     ACTOR

        ; Music Play
        VM_MUSIC_PLAY           ___bank_music_track_0__Data, _music_track_0__Data, .MUSIC_LOOP

        ; Timer Start
        VM_TIMER_PREPARE        1, ___bank_script_timer_0, _script_timer_0
        VM_TIMER_SET            1, 1

        ; Input Script Attach
        VM_CONTEXT_PREPARE      1, ___bank_script_input_1, _script_input_1
        VM_INPUT_ATTACH         240, ^/(1 | .OVERRIDE_DEFAULT)/

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_SET_CONST_INT8       _fade_frames_per_step, 1
        VM_FADE_IN              1

        ; Stop Script
        VM_STOP
