;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module avatar_font
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _vwf_font_avatars
	.globl ___bank_vwf_font_avatars
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
_font_avatars_table:
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x04	; 4
	.db #0x05	; 5
	.db #0x06	; 6
	.db #0x07	; 7
_font_avatars_bitmaps:
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0xe0	; 224
	.db #0x60	; 96
	.db #0xfb	; 251
	.db #0x5b	; 91
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xee	; 238
	.db #0x7f	; 127
	.db #0xee	; 238
	.db #0x7b	; 123
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0x7f	; 127
	.db #0x0e	; 14
	.db #0x3f	; 63
	.db #0x1f	; 31
	.db #0x3f	; 63
	.db #0x1f	; 31
	.db #0x3f	; 63
	.db #0x1f	; 31
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x7f	; 127
	.db #0x3f	; 63
	.db #0x7f	; 127
	.db #0x37	; 55	'7'
	.db #0x7f	; 127
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0xe0	; 224
	.db #0xc0	; 192
	.db #0xe0	; 224
	.db #0x40	; 64
	.db #0xe0	; 224
	.db #0xc0	; 192
	.db #0xe0	; 224
	.db #0x80	; 128
	.db #0xe6	; 230
	.db #0xc6	; 198
	.db #0xef	; 239
	.db #0xcf	; 207
	.db #0xff	; 255
	.db #0x99	; 153
	.db #0xff	; 255
	.db #0x10	; 16
	.db #0xb9	; 185
	.db #0x18	; 24
	.db #0xbc	; 188
	.db #0x8c	; 140
	.db #0xfe	; 254
	.db #0xc4	; 196
	.db #0xee	; 238
	.db #0xec	; 236
	.db #0xfe	; 254
	.db #0xf8	; 248
	.db #0xfc	; 252
	.db #0xf0	; 240
	.db #0xf8	; 248
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x1c	; 28
	.db #0x1c	; 28
	.db #0x37	; 55	'7'
	.db #0x2f	; 47
	.db #0x28	; 40
	.db #0x3f	; 63
	.db #0x3b	; 59
	.db #0x3e	; 62
	.db #0x30	; 48	'0'
	.db #0x3f	; 63
	.db #0x13	; 19
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x11	; 17
	.db #0x0e	; 14
	.db #0x09	; 9
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x1f	; 31
	.db #0x18	; 24
	.db #0x17	; 23
	.db #0x1c	; 28
	.db #0x17	; 23
	.db #0x1c	; 28
	.db #0x17	; 23
	.db #0x1c	; 28
	.db #0x3f	; 63
	.db #0x22	; 34
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x70	; 112	'p'
	.db #0x70	; 112	'p'
	.db #0xd8	; 216
	.db #0xe8	; 232
	.db #0x28	; 40
	.db #0xf8	; 248
	.db #0xb8	; 184
	.db #0xf8	; 248
	.db #0x18	; 24
	.db #0xf8	; 248
	.db #0x90	; 144
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x10	; 16
	.db #0xe0	; 224
	.db #0x20	; 32
	.db #0xe2	; 226
	.db #0xe2	; 226
	.db #0xf6	; 246
	.db #0x36	; 54	'6'
	.db #0xde	; 222
	.db #0x7a	; 122	'z'
	.db #0xdc	; 220
	.db #0x74	; 116	't'
	.db #0xd8	; 216
	.db #0x78	; 120	'x'
	.db #0xf8	; 248
	.db #0x88	; 136
	.db #0xf8	; 248
	.db #0xf8	; 248
___bank_vwf_font_avatars	=	0x00ff
_vwf_font_avatars:
	.db #0x01	; 1
	.db #0x07	; 7
	.dw _font_avatars_table
	.dw #0x0000
	.dw _font_avatars_bitmaps
	.area _INITIALIZER
	.area _CABS (ABS)
