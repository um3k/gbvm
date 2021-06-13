.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_music_0 = 255
.globl ___bank_script_music_0

_script_music_0::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; If Variable True
        VM_IF_CONST .GT         VAR_S9_LIGHTSSTATE, 0, 1$, 0
        ; Variable Set To True
        VM_SET_CONST            VAR_S9_LIGHTSSTATE, 1

        VM_LOAD_PALETTE         3, ^/(.PALETTE_BKG | .PALETTE_COMMIT)/
        .CGB_PAL                13, 0, 31, 5, 12, 30, 14, 6, 15, 4, 5, 10
        .CGB_PAL                31, 2, 2, 12, 20, 30, 25, 1, 6, 4, 5, 10
        VM_LOAD_PALETTE         3, ^/(.PALETTE_SPRITE | .PALETTE_COMMIT)/
        .CGB_PAL                31, 18, 18, 31, 18, 18, 30, 7, 7, 9, 4, 4
        .CGB_PAL                31, 18, 18, 31, 18, 18, 30, 7, 7, 9, 4, 4
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_RIGHT

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_RIGHT

        VM_JUMP                 2$
1$:
        VM_LOAD_PALETTE         3, ^/(.PALETTE_BKG | .PALETTE_COMMIT)/
        .CGB_PAL                31, 2, 2, 12, 20, 30, 25, 1, 6, 4, 5, 10
        .CGB_PAL                13, 0, 31, 5, 12, 30, 14, 6, 15, 4, 5, 10
        VM_LOAD_PALETTE         3, ^/(.PALETTE_SPRITE | .PALETTE_COMMIT)/
        .CGB_PAL                24, 12, 28, 24, 12, 28, 5, 11, 28, 9, 4, 10
        .CGB_PAL                24, 12, 28, 24, 12, 28, 5, 11, 28, 9, 4, 10
        ; Variable Set To False
        VM_SET_CONST            VAR_S9_LIGHTSSTATE, 0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_LEFT

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_LEFT

2$:

        ; Stop Script
        VM_STOP
