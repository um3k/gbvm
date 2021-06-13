.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s1_init = 255
.globl ___bank_script_s1_init

_script_s1_init::
        VM_MUSIC_PLAY           ___bank_music_track_101__Data, _music_track_101__Data, .MUSIC_LOOP

        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        ; If Variable True
        VM_IF_CONST .EQ         VAR_PUSHED_ICE_BLOCK, 1, 1$, 0
        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2
        VM_ACTOR_ACTIVATE       ACTOR
        ; Actor Set Position
        ; NOT IMPLEMENTED
2$:
        ; Fade IN
        VM_FADE_IN              .UI_MODAL
        ; Stop Script
        VM_STOP
