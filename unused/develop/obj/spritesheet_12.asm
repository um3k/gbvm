;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module spritesheet_12
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _spritesheet_12
	.globl _spritesheet_12_animations_lookup
	.globl _spritesheet_12_animations
	.globl _spritesheet_12_metasprites
	.globl _spritesheet_12_metasprite_climb_2
	.globl _spritesheet_12_metasprite_climb_1
	.globl _spritesheet_12_metasprite_left_jump_1
	.globl _spritesheet_12_metasprite_right_jump_1
	.globl _spritesheet_12_metasprite_left_walk_3
	.globl _spritesheet_12_metasprite_left_walk_2
	.globl _spritesheet_12_metasprite_left_walk_1
	.globl _spritesheet_12_metasprite_right_walk_3
	.globl _spritesheet_12_metasprite_right_walk_2
	.globl _spritesheet_12_metasprite_right_walk_1
	.globl _spritesheet_12_metasprite_left_idle_3
	.globl _spritesheet_12_metasprite_left_idle_2
	.globl _spritesheet_12_metasprite_left_idle_1
	.globl _spritesheet_12_metasprite_right_idle_3
	.globl _spritesheet_12_metasprite_right_idle_2
	.globl _spritesheet_12_metasprite_right_idle_1
	.globl ___bank_spritesheet_12
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
___bank_spritesheet_12	=	0x00ff
_spritesheet_12_metasprite_right_idle_1:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x0d	;  13
	.db #0xf8	; -8
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0c	; 12
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_right_idle_2:
	.db #0xf4	; -12
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x0c	;  12
	.db #0xf8	; -8
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0c	; 12
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_right_idle_3:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x0d	;  13
	.db #0xf8	; -8
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0c	; 12
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_left_idle_1:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x02	; 2
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x0d	;  13
	.db #0xf8	; -8
	.db #0x0c	; 12
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0a	; 10
	.db #0x20	; 32
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_left_idle_2:
	.db #0xf4	; -12
	.db #0x00	;  0
	.db #0x02	; 2
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x0c	;  12
	.db #0xf8	; -8
	.db #0x0c	; 12
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0a	; 10
	.db #0x20	; 32
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_left_idle_3:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x04	; 4
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x0d	;  13
	.db #0xf8	; -8
	.db #0x0c	; 12
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0a	; 10
	.db #0x20	; 32
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_right_walk_1:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x0d	;  13
	.db #0xf8	; -8
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x10	; 16
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_right_walk_2:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x0d	;  13
	.db #0xf8	; -8
	.db #0x12	; 18
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x14	; 20
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_right_walk_3:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x0d	;  13
	.db #0xf8	; -8
	.db #0x16	; 22
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_left_walk_1:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x02	; 2
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x0d	;  13
	.db #0xf8	; -8
	.db #0x10	; 16
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0e	; 14
	.db #0x20	; 32
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_left_walk_2:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x02	; 2
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x0d	;  13
	.db #0xf8	; -8
	.db #0x14	; 20
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x12	; 18
	.db #0x20	; 32
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_left_walk_3:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x02	; 2
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x0d	;  13
	.db #0xf8	; -8
	.db #0x18	; 24
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x16	; 22
	.db #0x20	; 32
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_right_jump_1:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x0d	;  13
	.db #0xf8	; -8
	.db #0x1a	; 26
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1c	; 28
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_left_jump_1:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x02	; 2
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x0d	;  13
	.db #0xf8	; -8
	.db #0x1c	; 28
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1a	; 26
	.db #0x20	; 32
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprite_climb_1:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x08	; 8
	.db #0x00	; 0
	.db #0x0c	;  12
	.db #0xf8	; -8
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
_spritesheet_12_metasprite_climb_2:
	.db #0xf3	; -13
	.db #0x00	;  0
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x08	; 8
	.db #0x00	; 0
	.db #0x0c	;  12
	.db #0xf8	; -8
	.db #0x20	; 32
	.db #0x20	; 32
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x1e	; 30
	.db #0x20	; 32
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_spritesheet_12_metasprites:
	.dw _spritesheet_12_metasprite_right_idle_1
	.dw _spritesheet_12_metasprite_right_idle_1
	.dw _spritesheet_12_metasprite_right_idle_1
	.dw _spritesheet_12_metasprite_right_idle_3
	.dw _spritesheet_12_metasprite_right_idle_1
	.dw _spritesheet_12_metasprite_right_idle_1
	.dw _spritesheet_12_metasprite_right_idle_1
	.dw _spritesheet_12_metasprite_right_idle_2
	.dw _spritesheet_12_metasprite_left_idle_1
	.dw _spritesheet_12_metasprite_left_idle_1
	.dw _spritesheet_12_metasprite_left_idle_1
	.dw _spritesheet_12_metasprite_left_idle_3
	.dw _spritesheet_12_metasprite_left_idle_1
	.dw _spritesheet_12_metasprite_left_idle_1
	.dw _spritesheet_12_metasprite_left_idle_1
	.dw _spritesheet_12_metasprite_left_idle_2
	.dw _spritesheet_12_metasprite_right_walk_1
	.dw _spritesheet_12_metasprite_right_walk_2
	.dw _spritesheet_12_metasprite_right_walk_3
	.dw _spritesheet_12_metasprite_left_walk_1
	.dw _spritesheet_12_metasprite_left_walk_2
	.dw _spritesheet_12_metasprite_left_walk_3
	.dw _spritesheet_12_metasprite_right_jump_1
	.dw _spritesheet_12_metasprite_left_jump_1
	.dw _spritesheet_12_metasprite_climb_1
	.dw _spritesheet_12_metasprite_climb_2
_spritesheet_12_animations:
	.db #0x17	; 23
	.db #0x17	; 23
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x08	; 8
	.db #0x0f	; 15
	.db #0x17	; 23
	.db #0x17	; 23
	.db #0x10	; 16
	.db #0x12	; 18
	.db #0x18	; 24
	.db #0x19	; 25
	.db #0x13	; 19
	.db #0x15	; 21
_spritesheet_12_animations_lookup:
	.dw #0x0000
_spritesheet_12:
	.db #0x06	; 6
	.dw _spritesheet_12_metasprites
	.dw _spritesheet_12_animations
	.dw _spritesheet_12_animations_lookup
	.db #0x00	;  0
	.db #0x0f	;  15
	.db #0xf8	; -8
	.db #0x07	;  7
	.byte ___bank_spritesheet_12_tiles
	.dw _spritesheet_12_tiles
	.db #0x00	; 0
	.dw #0x0000
	.area _INITIALIZER
	.area _CABS (ABS)
