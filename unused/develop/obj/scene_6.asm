;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module scene_6
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _scene_6
	.globl ___bank_scene_6
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
___bank_scene_6	=	0x00ff
_scene_6:
	.db #0x14	; 20
	.db #0x12	; 18
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x01	; 1
	.byte ___bank_spritesheet_0
	.dw _spritesheet_0
	.byte ___bank_background_6
	.dw _background_6
	.byte ___bank_scene_6_collisions
	.dw _scene_6_collisions
	.byte ___bank_palette_2
	.dw _palette_2
	.byte ___bank_palette_0
	.dw _palette_0
	.byte ___bank_script_s5_init
	.dw _script_s5_init
	.byte #0x00
	.dw #0x0000
	.byte #0x00
	.dw #0x0000
	.byte #0x00
	.dw #0x0000
	.byte ___bank_scene_6_sprites
	.dw _scene_6_sprites
	.byte ___bank_scene_6_actors
	.dw _scene_6_actors
	.byte ___bank_scene_6_triggers
	.dw _scene_6_triggers
	.byte #0x00
	.dw #0x0000
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x14	; 20
	.db #0x00	; 0
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.area _INITIALIZER
	.area _CABS (ABS)
