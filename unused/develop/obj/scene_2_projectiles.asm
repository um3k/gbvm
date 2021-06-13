;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module scene_2_projectiles
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _scene_2_projectiles
	.globl ___bank_scene_2_projectiles
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
___bank_scene_2_projectiles	=	0x00ff
_scene_2_projectiles:
	.db #0x00	;  0
	.db #0x10	;  16
	.db #0xf0	; -16
	.db #0x00	;  0
	.byte ___bank_spritesheet_5
	.dw _spritesheet_5
	.db #0x3c	; 60
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x02	; 2
	.db #0x07	; 7
	.db #0x3c	; 60
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x10	;  16
	.db #0xf0	; -16
	.db #0x00	;  0
	.byte ___bank_spritesheet_9
	.dw _spritesheet_9
	.db #0x78	; 120	'x'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0x20	; 32
	.db #0x00	; 0
	.area _INITIALIZER
	.area _CABS (ABS)
