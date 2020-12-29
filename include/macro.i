.macro FAR_PTR SYM
    .db b'SYM
    .dw SYM
.endm
.macro IMPORT_FAR_PTR SYM
    .globl SYM, b'SYM
    FAR_PTR SYM
.endm
