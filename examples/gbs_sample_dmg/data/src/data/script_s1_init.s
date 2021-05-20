.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s1_init = 255
.globl ___bank_script_s1_init

_script_s1_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 7

        ; Actor Set Collisions
        VM_ACTOR_SET_COLL_ENABLED ACTOR, 0

        ; Call Script: Initialize Menu
        VM_CALL_FAR             ___bank_script_initialize_menu, _script_initialize_menu

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Stop Script
        VM_STOP
