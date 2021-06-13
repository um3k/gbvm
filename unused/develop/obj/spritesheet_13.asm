;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module spritesheet_13
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _spritesheet_13
	.globl _spritesheet_13_animations_lookup
	.globl _spritesheet_13_animations
	.globl _spritesheet_13_metasprites
	.globl _spritesheet_13_metasprite_1
	.globl _spritesheet_13_metasprite_0
	.globl ___bank_spritesheet_13
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
___bank_spritesheet_13	=	0x00ff
_spritesheet_13_metasprite_0:
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_13_metasprite_1:
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_13_metasprites:
	.dw _spritesheet_13_metasprite_0
	.dw _spritesheet_13_metasprite_1
_spritesheet_13_animations:
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x01	; 1
_spritesheet_13_animations_lookup:
	.dw #0x0000
_spritesheet_13:
	.db #0x02	; 2
	.dw _spritesheet_13_metasprites
	.dw _spritesheet_13_animations
	.dw _spritesheet_13_animations_lookup
	.db #0x00	;  0
	.db #0x0f	;  15
	.db #0xf8	; -8
	.db #0x07	;  7
	.byte ___bank_spritesheet_13_tiles
	.dw _spritesheet_13_tiles
	.db #0x00	; 0
	.dw #0x0000
	.area _INITIALIZER
	.area _CABS (ABS)
