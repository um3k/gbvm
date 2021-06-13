;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module scene_4_triggers
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _scene_4_triggers
	.globl ___bank_scene_4_triggers
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
___bank_scene_4_triggers	=	0x00ff
_scene_4_triggers:
	.db #0xa0	; 160
	.db #0x0d	; 13
	.db #0x01	; 1
	.db #0x01	; 1
	.byte ___bank_script_s4t0_interact
	.dw _script_s4t0_interact
	.db #0x06	; 6
	.db #0x0d	; 13
	.db #0x02	; 2
	.db #0x01	; 1
	.byte ___bank_script_s4t1_interact
	.dw _script_s4t1_interact
	.db #0x38	; 56	'8'
	.db #0x11	; 17
	.db #0x03	; 3
	.db #0x01	; 1
	.byte ___bank_script_s4t2_interact
	.dw _script_s4t2_interact
	.db #0x0e	; 14
	.db #0x08	; 8
	.db #0x01	; 1
	.db #0x01	; 1
	.byte ___bank_script_s4t3_interact
	.dw _script_s4t3_interact
	.db #0x6a	; 106	'j'
	.db #0x11	; 17
	.db #0x05	; 5
	.db #0x01	; 1
	.byte ___bank_script_s4t4_interact
	.dw _script_s4t4_interact
	.area _INITIALIZER
	.area _CABS (ABS)
