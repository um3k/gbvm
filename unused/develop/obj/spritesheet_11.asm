;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module spritesheet_11
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _spritesheet_11
	.globl _spritesheet_11_animations_lookup
	.globl _spritesheet_11_animations
	.globl _spritesheet_11_metasprites
	.globl _spritesheet_11_metasprite_1
	.globl _spritesheet_11_metasprite_0
	.globl ___bank_spritesheet_11
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
___bank_spritesheet_11	=	0x00ff
_spritesheet_11_metasprite_0:
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x10	; 16
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x10	; 16
	.db #0x00	;  0
	.db #0xf8	; -8
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
_spritesheet_11_metasprite_1:
	.db #0x00	;  0
	.db #0x04	;  4
	.db #0x08	; 8
	.db #0x10	; 16
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_11_metasprites:
	.dw _spritesheet_11_metasprite_0
	.dw _spritesheet_11_metasprite_1
_spritesheet_11_animations:
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x01	; 1
_spritesheet_11_animations_lookup:
	.dw #0x0000
_spritesheet_11:
	.db #0x02	; 2
	.dw _spritesheet_11_metasprites
	.dw _spritesheet_11_animations
	.dw _spritesheet_11_animations_lookup
	.db #0x00	;  0
	.db #0x0f	;  15
	.db #0xf8	; -8
	.db #0x07	;  7
	.byte ___bank_spritesheet_11_tiles
	.dw _spritesheet_11_tiles
	.db #0x00	; 0
	.dw #0x0000
	.area _INITIALIZER
	.area _CABS (ABS)
