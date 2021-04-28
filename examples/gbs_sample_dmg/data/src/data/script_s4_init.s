.include "vm.i"
.include "data/game_globals.i"
.include "macro.i"

.globl b_wait_frames, _wait_frames, ___bank_scene_5, _scene_5

.area _CODE_255

ACTOR = -4

___bank_script_s4_init = 255
.globl ___bank_script_s4_init

_script_s4_init::
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

        ; Overlay Show
        VM_OVERLAY_SHOW         0, 0, 0, 0

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Overlay Move To
        VM_OVERLAY_MOVE_TO      0, 18, 2
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW)/

        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Load Scene
        VM_FADE_OUT             2
        VM_SET_CONST            ACTOR, 0
        VM_SET_CONST            ^/(ACTOR + 1)/, 0
        VM_SET_CONST            ^/(ACTOR + 2)/, 0
        VM_ACTOR_SET_POS        ACTOR
        VM_ACTOR_SET_DIR        ACTOR, .DIR_DOWN
        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3
            IMPORT_FAR_PTR_DATA _scene_5

        ; Stop Script
        VM_STOP
