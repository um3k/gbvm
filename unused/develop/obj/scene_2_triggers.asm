;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module scene_2_triggers
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _scene_2_triggers
	.globl ___bank_scene_2_triggers
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
___bank_scene_2_triggers	=	0x00ff
_scene_2_triggers:
	.db #0x19	; 25
	.db #0x0d	; 13
	.db #0x02	; 2
	.db #0x02	; 2
	.byte ___bank_script_s2t0_interact
	.dw _script_s2t0_interact
	.db #0x18	; 24
	.db #0x08	; 8
	.db #0x02	; 2
	.db #0x01	; 1
	.byte ___bank_script_s2t1_interact
	.dw _script_s2t1_interact
	.db #0x0a	; 10
	.db #0x08	; 8
	.db #0x02	; 2
	.db #0x01	; 1
	.byte ___bank_script_s2t2_interact
	.dw _script_s2t2_interact
	.area _INITIALIZER
	.area _CABS (ABS)
