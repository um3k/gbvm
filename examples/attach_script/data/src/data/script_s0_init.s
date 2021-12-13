.module script_s0_init

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames, _text_ff_joypad, _text_draw_speed, _text_out_speed, _text_in_speed

.area _CODE_255


___bank_script_s0_init = 255
.globl ___bank_script_s0_init

_script_s0_init::
        VM_LOCK

        ; Variable Set To Value
        VM_SET_CONST            VAR_MENU_ITEM, 10

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Text Set Animation Speed
        VM_SET_CONST_INT8       _text_ff_joypad, 1
        VM_SET_CONST_INT8       _text_draw_speed, 1
        VM_SET_CONST_INT8       _text_out_speed, -3
        VM_SET_CONST_INT8       _text_in_speed, 0

        ; Variable Set To Value
        VM_SET_CONST            VAR_VARIABLE_101, 10

        ; Variable Set To Value
        VM_SET_CONST            VAR_VARIABLE_102, 20

        ; Variable Set To Value
        VM_SET_CONST            VAR_VARIABLE_103, 20

        ; Variable Set To Value
        VM_SET_CONST            VAR_VARIABLE_104, 50

        ; Advanced Menu
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_SPEED_INSTANT
        VM_LOAD_TEXT            4
        .dw VAR_VARIABLE_101, VAR_VARIABLE_102, VAR_VARIABLE_103, VAR_VARIABLE_104
        .asciz "\001\1\003\003\003Potion\003\003\004Sword\003\003\005Shield\003\003\006Armor\003\020\003%d\003\020\004%d\003\020\005%d\003\020\006%d \003\020\011Exit\003\002\001Shop\003\016\002Price"
        VM_OVERLAY_CLEAR        0, 0, 20, 10, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 8, .OVERLAY_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_CHOICE               VAR_MENU_ITEM, .UI_MENU_CANCEL_B, 11
            .MENUITEM           1, 2, 1, 1, 9, 2
            .MENUITEM           1, 3, 2, 2, 1, 3
            .MENUITEM           1, 4, 3, 3, 2, 4
            .MENUITEM           1, 5, 4, 4, 3, 9
            .MENUITEM           14, 2, 0, 0, 0, 0
            .MENUITEM           14, 3, 0, 0, 0, 0
            .MENUITEM           14, 4, 0, 0, 0, 0
            .MENUITEM           14, 5, 0, 0, 0, 0
            .MENUITEM           14, 8, 4, 1, 4, 1
            .MENUITEM           0, 0, 0, 0, 0, 0
            .MENUITEM           12, 1, 0, 0, 0, 0
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_SPEED_INSTANT

        ; Text Dialogue
        VM_LOAD_TEXT            2
        .dw VAR_MENU_ITEM, VAR_MENU_ITEM
        .asciz "1234 %d\n%c "
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Input Script Attach
        VM_CONTEXT_PREPARE      4, ___bank_script_input_0, _script_input_0
        VM_INPUT_ATTACH         16, 4

        ; Input Script Attach
        VM_CONTEXT_PREPARE      3, ___bank_script_input_1, _script_input_1
        VM_INPUT_ATTACH         32, 3

        ; Input Script Attach
        VM_CONTEXT_PREPARE      1, ___bank_script_input_2, _script_input_2
        VM_INPUT_ATTACH         128, 1

        ; Input Script Attach
        VM_CONTEXT_PREPARE      2, ___bank_script_input_3, _script_input_3
        VM_INPUT_ATTACH         64, 2

        ; Stop Script
        VM_STOP
