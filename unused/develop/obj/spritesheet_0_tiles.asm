;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module spritesheet_0_tiles
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _spritesheet_0_tiles
	.globl ___bank_spritesheet_0_tiles
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
___bank_spritesheet_0_tiles	=	0x00ff
_spritesheet_0_tiles:
	.dw #0x0018
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0x08	; 8
	.db #0x0f	; 15
	.db #0x10	; 16
	.db #0x1f	; 31
	.db #0x3d	; 61
	.db #0x23	; 35
	.db #0x22	; 34
	.db #0x3f	; 63
	.db #0x2d	; 45
	.db #0x3e	; 62
	.db #0x2b	; 43
	.db #0x3c	; 60
	.db #0x2b	; 43
	.db #0x3e	; 62
	.db #0x2f	; 47
	.db #0x3a	; 58
	.db #0x3f	; 63
	.db #0x2c	; 44
	.db #0x6f	; 111	'o'
	.db #0x5f	; 95
	.db #0x7f	; 127
	.db #0x7f	; 127
	.db #0x39	; 57	'9'
	.db #0x3f	; 63
	.db #0x1d	; 29
	.db #0x1b	; 27
	.db #0x0e	; 14
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0x10	; 16
	.db #0xf0	; 240
	.db #0x38	; 56	'8'
	.db #0xc8	; 200
	.db #0x5c	; 92
	.db #0xa4	; 164
	.db #0xac	; 172
	.db #0xd4	; 212
	.db #0x42	; 66	'B'
	.db #0xfe	; 254
	.db #0xbe	; 190
	.db #0x7e	; 126
	.db #0xd4	; 212
	.db #0x7c	; 124
	.db #0xf4	; 244
	.db #0x5c	; 92
	.db #0xf4	; 244
	.db #0x3c	; 60
	.db #0xfa	; 250
	.db #0xfe	; 254
	.db #0x3c	; 60
	.db #0xe4	; 228
	.db #0xfc	; 252
	.db #0xe4	; 228
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0x70	; 112	'p'
	.db #0x70	; 112	'p'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0x08	; 8
	.db #0x0f	; 15
	.db #0x10	; 16
	.db #0x1f	; 31
	.db #0x3d	; 61
	.db #0x23	; 35
	.db #0x22	; 34
	.db #0x3f	; 63
	.db #0x2d	; 45
	.db #0x3e	; 62
	.db #0x2b	; 43
	.db #0x3c	; 60
	.db #0x2b	; 43
	.db #0x3e	; 62
	.db #0x2f	; 47
	.db #0x3a	; 58
	.db #0x3f	; 63
	.db #0x2c	; 44
	.db #0x6f	; 111	'o'
	.db #0x5f	; 95
	.db #0x7c	; 124
	.db #0x7f	; 127
	.db #0x3f	; 63
	.db #0x27	; 39
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x0e	; 14
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0x10	; 16
	.db #0xf0	; 240
	.db #0x38	; 56	'8'
	.db #0xc8	; 200
	.db #0x5c	; 92
	.db #0xa4	; 164
	.db #0xac	; 172
	.db #0xd4	; 212
	.db #0x42	; 66	'B'
	.db #0xfe	; 254
	.db #0xbe	; 190
	.db #0x7e	; 126
	.db #0xd4	; 212
	.db #0x7c	; 124
	.db #0xf4	; 244
	.db #0x5c	; 92
	.db #0xf4	; 244
	.db #0x3c	; 60
	.db #0xf2	; 242
	.db #0xfe	; 254
	.db #0xfe	; 254
	.db #0xfe	; 254
	.db #0x9c	; 156
	.db #0xfc	; 252
	.db #0xb8	; 184
	.db #0xd8	; 216
	.db #0x70	; 112	'p'
	.db #0x70	; 112	'p'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0x08	; 8
	.db #0x0f	; 15
	.db #0x16	; 22
	.db #0x19	; 25
	.db #0x21	; 33
	.db #0x3e	; 62
	.db #0x60	; 96
	.db #0x7f	; 127
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x29	; 41
	.db #0x36	; 54	'6'
	.db #0x29	; 41
	.db #0x36	; 54	'6'
	.db #0x29	; 41
	.db #0x36	; 54	'6'
	.db #0x55	; 85	'U'
	.db #0x6a	; 106	'j'
	.db #0x7e	; 126
	.db #0x7d	; 125
	.db #0x3f	; 63
	.db #0x27	; 39
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0x10	; 16
	.db #0xf0	; 240
	.db #0x68	; 104	'h'
	.db #0x98	; 152
	.db #0x84	; 132
	.db #0x7c	; 124
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0x24	; 36
	.db #0xdc	; 220
	.db #0x24	; 36
	.db #0xdc	; 220
	.db #0x24	; 36
	.db #0xdc	; 220
	.db #0xa2	; 162
	.db #0xde	; 222
	.db #0x9e	; 158
	.db #0xfe	; 254
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0xb0	; 176
	.db #0xd0	; 208
	.db #0x70	; 112	'p'
	.db #0x70	; 112	'p'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0x08	; 8
	.db #0x0f	; 15
	.db #0x16	; 22
	.db #0x19	; 25
	.db #0x21	; 33
	.db #0x3e	; 62
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x60	; 96
	.db #0x7f	; 127
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x29	; 41
	.db #0x36	; 54	'6'
	.db #0x29	; 41
	.db #0x36	; 54	'6'
	.db #0x29	; 41
	.db #0x36	; 54	'6'
	.db #0x55	; 85	'U'
	.db #0x6a	; 106	'j'
	.db #0x7e	; 126
	.db #0x7d	; 125
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x0d	; 13
	.db #0x0b	; 11
	.db #0x0e	; 14
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0x10	; 16
	.db #0xf0	; 240
	.db #0x68	; 104	'h'
	.db #0x98	; 152
	.db #0x84	; 132
	.db #0x7c	; 124
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0x24	; 36
	.db #0xdc	; 220
	.db #0x24	; 36
	.db #0xdc	; 220
	.db #0x24	; 36
	.db #0xdc	; 220
	.db #0xa2	; 162
	.db #0xde	; 222
	.db #0x9e	; 158
	.db #0xfe	; 254
	.db #0xfc	; 252
	.db #0xe4	; 228
	.db #0xf8	; 248
	.db #0xf8	; 248
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x0c	; 12
	.db #0x0f	; 15
	.db #0x16	; 22
	.db #0x19	; 25
	.db #0x2a	; 42
	.db #0x37	; 55	'7'
	.db #0x24	; 36
	.db #0x3f	; 63
	.db #0x29	; 41
	.db #0x3e	; 62
	.db #0x27	; 39
	.db #0x3f	; 63
	.db #0x22	; 34
	.db #0x3f	; 63
	.db #0x33	; 51	'3'
	.db #0x2e	; 46
	.db #0x33	; 51	'3'
	.db #0x2f	; 47
	.db #0x7c	; 124
	.db #0x47	; 71	'G'
	.db #0x39	; 57	'9'
	.db #0x3f	; 63
	.db #0x1f	; 31
	.db #0x13	; 19
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x06	; 6
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x38	; 56	'8'
	.db #0xc8	; 200
	.db #0x0c	; 12
	.db #0xf4	; 244
	.db #0x62	; 98	'b'
	.db #0xbe	; 190
	.db #0xd2	; 210
	.db #0x7e	; 126
	.db #0xac	; 172
	.db #0xdc	; 220
	.db #0x38	; 56	'8'
	.db #0xc8	; 200
	.db #0xf8	; 248
	.db #0x28	; 40
	.db #0xfc	; 252
	.db #0x24	; 36
	.db #0xf8	; 248
	.db #0x08	; 8
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x30	; 48	'0'
	.db #0xd0	; 208
	.db #0xf8	; 248
	.db #0xe8	; 232
	.db #0x5c	; 92
	.db #0x64	; 100	'd'
	.db #0x38	; 56	'8'
	.db #0x38	; 56	'8'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x0c	; 12
	.db #0x0f	; 15
	.db #0x16	; 22
	.db #0x19	; 25
	.db #0x2a	; 42
	.db #0x37	; 55	'7'
	.db #0x24	; 36
	.db #0x3f	; 63
	.db #0x29	; 41
	.db #0x3e	; 62
	.db #0x27	; 39
	.db #0x3f	; 63
	.db #0x22	; 34
	.db #0x3f	; 63
	.db #0x33	; 51	'3'
	.db #0x2e	; 46
	.db #0x31	; 49	'1'
	.db #0x2f	; 47
	.db #0x7e	; 126
	.db #0x43	; 67	'C'
	.db #0x3e	; 62
	.db #0x3f	; 63
	.db #0x37	; 55	'7'
	.db #0x3f	; 63
	.db #0x17	; 23
	.db #0x19	; 25
	.db #0x0e	; 14
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x38	; 56	'8'
	.db #0xc8	; 200
	.db #0x0c	; 12
	.db #0xf4	; 244
	.db #0x62	; 98	'b'
	.db #0xbe	; 190
	.db #0xd2	; 210
	.db #0x7e	; 126
	.db #0xac	; 172
	.db #0xdc	; 220
	.db #0x38	; 56	'8'
	.db #0xc8	; 200
	.db #0xf8	; 248
	.db #0x28	; 40
	.db #0xfc	; 252
	.db #0x24	; 36
	.db #0xf8	; 248
	.db #0x08	; 8
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x50	; 80	'P'
	.db #0xf0	; 240
	.db #0xfc	; 252
	.db #0x3c	; 60
	.db #0xfc	; 252
	.db #0xfc	; 252
	.db #0x30	; 48	'0'
	.db #0x30	; 48	'0'
	.area _INITIALIZER
	.area _CABS (ABS)
