;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module tileset_7_1
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _tileset_7_1
	.globl ___bank_tileset_7_1
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
___bank_tileset_7_1	=	0x00ff
_tileset_7_1:
	.dw #0x000c
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0xee	; 238
	.db #0xff	; 255
	.db #0xc6	; 198
	.db #0xff	; 255
	.db #0xc6	; 198
	.db #0xff	; 255
	.db #0xc6	; 198
	.db #0xff	; 255
	.db #0xee	; 238
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x18	; 24
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x18	; 24
	.db #0xff	; 255
	.db #0x18	; 24
	.db #0xff	; 255
	.db #0x3e	; 62
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0xce	; 206
	.db #0xff	; 255
	.db #0x9c	; 156
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0xe6	; 230
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x7e	; 126
	.db #0xff	; 255
	.db #0xcc	; 204
	.db #0xff	; 255
	.db #0x98	; 152
	.db #0xff	; 255
	.db #0x3c	; 60
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0xce	; 206
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0x08	; 8
	.db #0xff	; 255
	.db #0x60	; 96
	.db #0xff	; 255
	.db #0xc8	; 200
	.db #0xff	; 255
	.db #0xd8	; 216
	.db #0xff	; 255
	.db #0x7e	; 126
	.db #0xff	; 255
	.db #0x18	; 24
	.db #0xff	; 255
	.db #0x18	; 24
	.db #0xff	; 255
	.db #0x10	; 16
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0x66	; 102	'f'
	.db #0xff	; 255
	.db #0x60	; 96
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0xce	; 206
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x3c	; 60
	.db #0xff	; 255
	.db #0x60	; 96
	.db #0xff	; 255
	.db #0xdc	; 220
	.db #0xff	; 255
	.db #0xf6	; 246
	.db #0xff	; 255
	.db #0xc2	; 194
	.db #0xff	; 255
	.db #0xe6	; 230
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x7e	; 126
	.db #0xff	; 255
	.db #0xe6	; 230
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0x1c	; 28
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x30	; 48	'0'
	.db #0xff	; 255
	.db #0x30	; 48	'0'
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0xee	; 238
	.db #0xff	; 255
	.db #0xc6	; 198
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0xc6	; 198
	.db #0xff	; 255
	.db #0xee	; 238
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0xce	; 206
	.db #0xff	; 255
	.db #0x86	; 134
	.db #0xff	; 255
	.db #0xde	; 222
	.db #0xff	; 255
	.db #0x76	; 118	'v'
	.db #0xff	; 255
	.db #0x0c	; 12
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x18	; 24
	.db #0xff	; 255
	.db #0x18	; 24
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x18	; 24
	.db #0xff	; 255
	.db #0x18	; 24
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.area _INITIALIZER
	.area _CABS (ABS)
