#pragma bank 2

#include "vm.h"

#include "load_save.h"

void vm_save_peek(SCRIPT_CTX * THIS, INT16 idxA, INT16 idxB, INT16 idxC, UBYTE count, UBYTE slot) __banked {
    INT16 * res, * dest;
    if (idxA < 0) res = THIS->stack_ptr + idxA; else res = script_memory + idxA;
    if (idxC < 0) {
        *res = FALSE;
        return;
    }
    if (idxB < 0) dest = THIS->stack_ptr + idxB; else dest = script_memory + idxB;
    *res = data_peek(slot, idxC, count, dest);
}

void vm_data_is_saved(SCRIPT_CTX * THIS, INT16 idx, UBYTE slot) __banked {
    INT16 * A;
    if (idx < 0) A = THIS->stack_ptr + idx; else A = script_memory + idx;
    *A = data_is_saved(slot);
}
