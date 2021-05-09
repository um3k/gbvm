.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s5_init = 255
.globl ___bank_script_s5_init

_script_s5_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST2, 0, 1$, 0
        ; Actor Hide
        VM_SET_CONST            ACTOR, 6
        VM_ACTOR_SET_HIDDEN     ACTOR, 1
        VM_ACTOR_DEACTIVATE     ACTOR

        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 6

        ; Actor Set Collisions
        VM_ACTOR_SET_COLL_ENABLED ACTOR, 0

2$:

        ; Call Script: Init Menu
        VM_CALL_FAR             ___bank_script_custom_0, _script_custom_0

        ; Music Play
        VM_MUSIC_PLAY           ___bank_music_track_7__Data, _music_track_7__Data, .MUSIC_LOOP

        ; If Variable True
        VM_IF_CONST .GT         VAR_PUSHED_ICE_BLOCK, 0, 3$, 0
        VM_JUMP                 4$
3$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Actor Set Position
        VM_SET_CONST            ^/(ACTOR + 1)/, 3072
        VM_SET_CONST            ^/(ACTOR + 2)/, 1920
        VM_ACTOR_SET_POS        ACTOR

4$:

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Stop Script
        VM_STOP
