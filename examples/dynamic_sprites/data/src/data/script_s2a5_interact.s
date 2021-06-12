.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s2a5_interact = 255
.globl ___bank_script_s2a5_interact

_script_s2a5_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0

        ; Actor Set Spritesheet
        VM_ACTOR_SET_SPRITESHEET ACTOR, ___bank_spritesheet_3, _spritesheet_3

        ; Stop Script
        VM_STOP
