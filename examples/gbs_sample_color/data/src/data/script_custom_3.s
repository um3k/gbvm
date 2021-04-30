.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_custom_3 = 255
.globl ___bank_script_custom_3

_script_custom_3::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG2 - 4)/
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Set Collisions
        VM_ACTOR_SET_COLL_ENABLED ACTOR, 0

        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG2 - 4)/
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Stop Update Script
        VM_ACTOR_TERMINATE_UPDATE ACTOR

        ; Sound Play Crash
        VM_SOUND_PLAY           30, 4, 0x01, 0xF2, 0x13, 0x80, 0x00
        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG2 - 4)/
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Set Spritesheet
        VM_ACTOR_SET_SPRITESHEET ACTOR, ___bank_spritesheet_3, _spritesheet_3

        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG2 - 4)/
        VM_ACTOR_ACTIVATE       ACTOR

        ; Wait N Frames
        VM_PUSH_CONST           30
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Actor Hide
        VM_SET                  ACTOR, ^/(.ARG2 - 4)/
        VM_ACTOR_SET_HIDDEN     ACTOR, 1
        VM_ACTOR_DEACTIVATE     ACTOR

        VM_POP                  4
        VM_RET_FAR
