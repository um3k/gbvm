.include "vm.i"
.include "data/game_globals.i"
.include "macro.i"

.globl b_wait_frames, _wait_frames, b_camera_shake_frames, _camera_shake_frames, ___bank_scene_7, _scene_7

.area _CODE_255

ACTOR = -4

___bank_script_s12t1_interact = 255
.globl ___bank_script_s12t1_interact

_script_s12t1_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; If Actor At Position
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    512
            .R_OPERATOR .EQ
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    1280
            .R_OPERATOR .EQ
            .R_OPERATOR .AND
            .R_STOP
        VM_IF_CONST .EQ         .ARG0, 0, 1$, 1
        ; Music Play
        VM_MUSIC_PLAY           ___bank_music_track_6__Data, _music_track_6__Data, .MUSIC_NO_LOOP

        ; Actor Hide
        VM_SET_CONST            ACTOR, 0
        VM_ACTOR_SET_HIDDEN     ACTOR, 1
        VM_ACTOR_DEACTIVATE     ACTOR

        ; Actor Show
        VM_SET_CONST            ACTOR, 1
        VM_ACTOR_SET_HIDDEN     ACTOR, 0
        VM_ACTOR_ACTIVATE       ACTOR

        ; Wait N Frames
        VM_PUSH_CONST           6
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1

        ; Actor Set Animation Frame
        VM_SET_CONST            ^/(ACTOR + 1)/, 1
        VM_ACTOR_SET_ANIM_FRAME ACTOR

        ; Wait N Frames
        VM_PUSH_CONST           6
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1

        ; Actor Set Animation Frame
        VM_SET_CONST            ^/(ACTOR + 1)/, 2
        VM_ACTOR_SET_ANIM_FRAME ACTOR

        ; Wait N Frames
        VM_PUSH_CONST           6
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Camera Shake
        VM_PUSH_CONST           60
        VM_PUSH_CONST           ^/(.CAMERA_SHAKE_X)/
        VM_INVOKE               b_camera_shake_frames, _camera_shake_frames, 2, .ARG1
        ; Variable Set To True
        VM_SET_CONST            VAR_QUEST9, 1

        ; Load Scene
        VM_FADE_OUT             2
        VM_SET_CONST            ACTOR, 0
        VM_SET_CONST            ^/(ACTOR + 1)/, 0
        VM_SET_CONST            ^/(ACTOR + 2)/, 1152
        VM_ACTOR_SET_POS        ACTOR
        VM_ACTOR_SET_DIR        ACTOR, .DIR_RIGHT
        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3
            IMPORT_FAR_PTR_DATA _scene_7

        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_RIGHT

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Hey! Do you want\nto end up in\nspace??"
        VM_OVERLAY_CLEAR        0, 0, 20, 5, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 13, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Because that's how\nyou end up in\nspace..."
        VM_OVERLAY_CLEAR        0, 0, 20, 5, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 13, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0

        ; Actor Move Relative
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    0
            .R_OPERATOR .ADD
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    256
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        ACTOR

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0

2$:

        ; Stop Script
        VM_STOP
