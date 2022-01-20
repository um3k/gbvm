.module script_s0t3_interact

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s0t3_interact = 255
.globl ___bank_script_s0t3_interact
.CURRENT_SCRIPT_BANK == ___bank_script_s0t3_interact

_script_s0t3_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0

        ; Actor Set Animation State
        VM_ACTOR_SET_ANIM_SET   ACTOR, STATE_IN_GRASS

        ; Stop Script
        VM_STOP
