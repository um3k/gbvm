.module script_s7a2_interact

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s7a2_interact = 255
.globl ___bank_script_s7a2_interact
.CURRENT_SCRIPT_BANK == ___bank_script_s7a2_interact

_script_s7a2_interact::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; If Parameter 0 Equals 0
        VM_PUSH_CONST           0
        VM_GET_TLOCAL           .ARG0, 0
        VM_IF_CONST .EQ         .ARG0, 0, 1$, 1
        VM_JUMP                 2$
1$:
        ; Call Script: Enemy Ship Hit Player
        VM_CALL_FAR             ___bank_script_enemy_ship_hit_player, _script_enemy_ship_hit_player

        ; Stop Script
        VM_STOP
2$:

        ; If Parameter 0 Equals 2
        VM_PUSH_CONST           0
        VM_GET_TLOCAL           .ARG0, 0
        VM_IF_CONST .EQ         .ARG0, 2, 3$, 1
        VM_JUMP                 4$
3$:
        ; Call Script: Enemy Ship Destroy
        VM_PUSH_CONST           3 ; Actor .ARG2
        VM_CALL_FAR             ___bank_script_enemy_ship_destroy, _script_enemy_ship_destroy
        VM_POP                  1

        ; Stop Script
        VM_STOP
4$:

        ; If Parameter 0 Equals 8
        VM_PUSH_CONST           0
        VM_GET_TLOCAL           .ARG0, 0
        VM_IF_CONST .EQ         .ARG0, 8, 5$, 1
        VM_JUMP                 6$
5$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 3

        ; Actor Set Spritesheet
        VM_ACTOR_SET_SPRITESHEET ACTOR, ___bank_spritesheet_4, _spritesheet_4

        ; Wait N Frames
        VM_PUSH_CONST           30
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Actor Hide
        VM_SET_CONST            ACTOR, 3
        VM_ACTOR_SET_HIDDEN     ACTOR, 1
        VM_ACTOR_DEACTIVATE     ACTOR

        ; Stop Script
        VM_STOP
6$:

        ; Stop Script
        VM_STOP
