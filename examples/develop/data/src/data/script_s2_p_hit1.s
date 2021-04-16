.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_s2_p_hit1 = 255
.globl ___bank_script_s2_p_hit1

.globl ___bank_spritesheet_0, _spritesheet_0
.globl ___bank_spritesheet_1, _spritesheet_1
.globl ___bank_spritesheet_11, _spritesheet_11
.globl ___bank_tileset_1, _tileset_1

_script_s2_p_hit1::

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "\002\001Hey!\nOuch!"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, .UI_DRAW_FRAME 
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; VM_MUSIC_STOP

        VM_IF_CONST .EQ         VAR_S2_GIRL_IS_COIN, 1, 1$, 0
        ; Emote
        VM_PUSH_CONST           1
        VM_ACTOR_EMOTE          .ARG0, ___bank_emote_1, _emote_1
        VM_ACTOR_SET_SPRITESHEET .ARG0, ___bank_spritesheet_11, _spritesheet_11
;        VM_ACTOR_REPLACE_TILE   .ARG0, 0, ___bank_tileset_1, _tileset_1, 0x07, 1 
;        VM_REPLACE_TILE         0x39, ___bank_tileset_1, _tileset_1, 0x41, 1
        VM_POP                  1
        VM_SET_CONST            VAR_S2_GIRL_IS_COIN, 1
        ; Stop Script
        VM_STOP

1$:
        VM_PUSH_CONST           1
        VM_ACTOR_EMOTE          .ARG0, ___bank_emote_0, _emote_0
        VM_ACTOR_SET_SPRITESHEET .ARG0, ___bank_spritesheet_0, _spritesheet_0
;        VM_ACTOR_REPLACE_TILE   .ARG0, 0, ___bank_tileset_1, _tileset_1, 0x40, 1
;        VM_REPLACE_TILE         0x39, ___bank_tileset_1, _tileset_1, 0x40, 1
        VM_POP                  1
        VM_SET_CONST            VAR_S2_GIRL_IS_COIN, 0
        ; Stop Script
        VM_STOP
