.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s1a1_interact = 255
.globl ___bank_script_s1a1_interact

_script_s1a1_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH                 0
        VM_PUSH                 0
        VM_PUSH                 0
        VM_PUSH                 0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2
        VM_ACTOR_ACTIVATE       ACTOR
        ; If Actor At Position
        ; NOT IMPLEMENTED - JUMPING TO FALSE PATH
        VM_JUMP                 1$
        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2
        VM_ACTOR_ACTIVATE       ACTOR
        ; Actor Push
        ; NOT IMPLEMENTED
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2
        VM_ACTOR_ACTIVATE       ACTOR
        ; If Actor At Position
        ; NOT IMPLEMENTED - JUMPING TO FALSE PATH
        VM_JUMP                 3$
        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Success!\n"
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        ; Variable Set To True
        VM_SET_CONST            VAR_QUEST2, 1
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 6
        VM_ACTOR_ACTIVATE       ACTOR
        ; Actor Show
        ; NOT IMPLEMENTED
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 6
        VM_ACTOR_ACTIVATE       ACTOR
        ; Actor Set Collisions
        ; NOT IMPLEMENTED
        VM_JUMP                 4$
3$:
4$:
2$:
        ; Variable Set To True
        VM_SET_CONST            VAR_PUSHED_ICE_BLOCK, 1
        ; Stop Script
        VM_STOP
