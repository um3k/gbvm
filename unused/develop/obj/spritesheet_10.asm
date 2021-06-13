;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module spritesheet_10
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _spritesheet_10
	.globl _spritesheet_10_animations_lookup
	.globl _spritesheet_10_animations
	.globl _spritesheet_10_metasprites
	.globl _spritesheet_10_metasprite_4
	.globl _spritesheet_10_metasprite_3
	.globl _spritesheet_10_metasprite_2
	.globl _spritesheet_10_metasprite_1
	.globl _spritesheet_10_metasprite_0
	.globl ___bank_spritesheet_10
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
___bank_spritesheet_10	=	0x00ff
_spritesheet_10_metasprite_0:
	.db #0xe0	; -32
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x08	; 8
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x10	;  16
	.db #0xd8	; -40
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0c	; 12
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x10	; 16
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x10	; 16
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x12	; 18
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x14	; 20
	.db #0x00	; 0
	.db #0x10	;  16
	.db #0xd0	; -48
	.db #0x16	; 22
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x10	;  16
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1a	; 26
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1c	; 28
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1e	; 30
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x20	; 32
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_10_metasprite_1:
	.db #0xe0	; -32
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x08	; 8
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x10	;  16
	.db #0xd8	; -40
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0c	; 12
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x10	; 16
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x10	; 16
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x12	; 18
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x22	; 34
	.db #0x00	; 0
	.db #0x10	;  16
	.db #0xc8	; -56
	.db #0x24	; 36
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x26	; 38
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x10	;  16
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1a	; 26
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1c	; 28
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1e	; 30
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x28	; 40
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_10_metasprite_2:
	.db #0xe0	; -32
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x08	; 8
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x10	;  16
	.db #0xd8	; -40
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0c	; 12
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x10	; 16
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x10	; 16
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x12	; 18
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x2a	; 42
	.db #0x00	; 0
	.db #0x10	;  16
	.db #0xc8	; -56
	.db #0x2c	; 44
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x2e	; 46
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x10	;  16
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1a	; 26
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1c	; 28
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1e	; 30
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x30	; 48	'0'
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_10_metasprite_3:
	.db #0xe0	; -32
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x08	; 8
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x10	;  16
	.db #0xd8	; -40
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0c	; 12
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x10	; 16
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x10	; 16
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x12	; 18
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x22	; 34
	.db #0x00	; 0
	.db #0x10	;  16
	.db #0xc8	; -56
	.db #0x32	; 50	'2'
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x34	; 52	'4'
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x10	;  16
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1a	; 26
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1c	; 28
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1e	; 30
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x28	; 40
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_10_metasprite_4:
	.db #0xe0	; -32
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x08	; 8
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x10	;  16
	.db #0xd8	; -40
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0c	; 12
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x10	; 16
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x10	; 16
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x12	; 18
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x14	; 20
	.db #0x00	; 0
	.db #0x10	;  16
	.db #0xc8	; -56
	.db #0x36	; 54	'6'
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x34	; 52	'4'
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x10	;  16
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1a	; 26
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1c	; 28
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1e	; 30
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x20	; 32
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_10_metasprites:
	.dw _spritesheet_10_metasprite_0
	.dw _spritesheet_10_metasprite_1
	.dw _spritesheet_10_metasprite_2
	.dw _spritesheet_10_metasprite_3
	.dw _spritesheet_10_metasprite_4
	.dw _spritesheet_10_metasprite_3
	.dw _spritesheet_10_metasprite_2
	.dw _spritesheet_10_metasprite_1
_spritesheet_10_animations:
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x00	; 0
	.db #0x07	; 7
_spritesheet_10_animations_lookup:
	.dw #0x0000
_spritesheet_10:
	.db #0x08	; 8
	.dw _spritesheet_10_metasprites
	.dw _spritesheet_10_animations
	.dw _spritesheet_10_animations_lookup
	.db #0x00	;  0
	.db #0x0f	;  15
	.db #0xf8	; -8
	.db #0x07	;  7
	.byte ___bank_spritesheet_10_tiles
	.dw _spritesheet_10_tiles
	.db #0x00	; 0
	.dw #0x0000
	.area _INITIALIZER
	.area _CABS (ABS)
