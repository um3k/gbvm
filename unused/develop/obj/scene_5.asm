;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module scene_5
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _scene_5
	.globl ___bank_scene_5
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE_255
	.area _CODE_255
___bank_scene_5	=	0x00ff
_scene_5:
	.db #0x50	; 80	'P'
	.db #0x12	; 18
	.db #0x01	; 1
	.db #0x04	; 4
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x03	; 3
	.byte ___bank_spritesheet_12
	.dw _spritesheet_12
	.byte ___bank_background_5
	.dw _background_5
	.byte ___bank_scene_5_collisions
	.dw _scene_5_collisions
	.byte ___bank_palette_2
	.dw _palette_2
	.byte ___bank_palette_4
	.dw _palette_4
	.byte ___bank_script_s5_init
	.dw _script_s5_init
	.byte #0x00
	.dw #0x0000
	.byte #0x00
	.dw #0x0000
	.byte #0x00
	.dw #0x0000
	.byte ___bank_scene_5_sprites
	.dw _scene_5_sprites
	.byte ___bank_scene_5_actors
	.dw _scene_5_actors
	.byte ___bank_scene_5_triggers
	.dw _scene_5_triggers
	.byte #0x00
	.dw #0x0000
	.db #0x00	; 0
	.db #0x4f	; 79	'O'
	.db #0x07	;  7
	.db #0x00	; 0
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x67	; 103	'g'
	.db #0x03	;  3
	.db #0x0a	; 10
	.db #0x03	; 3
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x0d	; 13
	.db #0x07	; 7
	.db #0x00	; 0
	.area _INITIALIZER
	.area _CABS (ABS)
