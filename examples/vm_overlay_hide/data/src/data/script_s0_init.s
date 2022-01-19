.module script_s0_init

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames, _fade_frames_per_step

.area _CODE_255

ACTOR = -4

___bank_script_s0_init = 255
.globl ___bank_script_s0_init
.CURRENT_SCRIPT_BANK == ___bank_script_s0_init

_script_s0_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Overlay Show
        VM_OVERLAY_SHOW         0, 8, 0, 0

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_SET_CONST_INT8       _fade_frames_per_step, 1
        VM_FADE_IN              1

        ; Overlay Move To
        VM_OVERLAY_MOVE_TO      0, 13, 2
        VM_OVERLAY_WAIT         .UI_MODAL, .UI_WAIT_WINDOW

        ; Overlay Hide
        VM_OVERLAY_HIDE

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 1152
        VM_SET_CONST            ^/(ACTOR + 2)/, 1920
        VM_SET_CONST            ^/(ACTOR + 3)/, .ACTOR_ATTR_H_FIRST
        VM_ACTOR_MOVE_TO        ACTOR

        ; Stop Script
        VM_STOP
