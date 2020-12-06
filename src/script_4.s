.include "vm.inc"
        
.globl b_actor_move_to, _actor_move_to
.globl b_wait_frames, _wait_frames

.area _CODE_3

___bank_SCRIPT_4 = 3
.globl ___bank_SCRIPT_4

_SCRIPT_4::

1$:
        ; Wait 1 Second
        VM_PUSH         60       ; Actor 1
        VM_INVOKE       b_wait_frames, _wait_frames, 1  ; call actor_move_to(), dispose 5 parameter on stack after

        ; Actor Move To
        VM_PUSH         7       ; Actor 7
        VM_PUSH         80      ; X = 80
        VM_PUSH         16      ; Y = 16
        VM_PUSH         0       ; Horizonal movement first
        VM_PUSH         0       ; Don't check collisions
        VM_INVOKE       b_actor_move_to, _actor_move_to, 5  ; call actor_move_to(), dispose 5 parameter on stack after

        ; Wait 1 Second
        VM_PUSH         60       ; Actor 1
        VM_INVOKE       b_wait_frames, _wait_frames, 1  ; call actor_move_to(), dispose 5 parameter on stack after

        ; Actor Move To
        VM_PUSH         7       ; Actor 7
        VM_PUSH         48      ; X = 48
        VM_PUSH         64      ; Y = 64
        VM_PUSH         0       ; Horizonal movement first
        VM_PUSH         0       ; Don't check collisions
        VM_INVOKE       b_actor_move_to, _actor_move_to, 5  ; call actor_move_to(), dispose 5 parameter on stack after

        VM_JUMP 1$
