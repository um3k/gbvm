.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s13_init = 255
.globl ___bank_script_s13_init

_script_s13_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST10, 0, 1$, 0
        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1

        ; Actor Set Animation Frame
        VM_SET_CONST            ^/(ACTOR + 1)/, 1
        VM_ACTOR_SET_ANIM_FRAME ACTOR

2$:

        ; Call Script: Init Menu
        VM_CALL_FAR             ___bank_script_init_menu, _script_init_menu

        ; Music Play
        VM_MUSIC_PLAY           ___bank_music_track_7__Data, _music_track_7__Data, .MUSIC_LOOP

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Stop Script
        VM_STOP
