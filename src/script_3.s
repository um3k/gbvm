.include "vm.inc"
        
.globl b_actor_move_to, _actor_move_to
.globl b_wait_frames, _wait_frames

.area _CODE_3

___bank_SCRIPT_3 = 3
.globl ___bank_SCRIPT_3

_SCRIPT_3::

1$:
        ; Wait 1 Second
        VM_PUSH         60
        VM_INVOKE       b_wait_frames, _wait_frames, 1  ; wait 1 second

        ; Actor Move To
        VM_PUSH         5       ; Actor 5
        VM_PUSH         0       ; X = 0
        VM_PUSH         16      ; Y = 16
        VM_PUSH         0       ; Horizonal movement first
        VM_PUSH         0       ; Don't check collisions
        VM_INVOKE       b_actor_move_to, _actor_move_to, 5  ; call actor_move_to(), dispose 5 parameter on stack after

        ; Wait 1 Second
        VM_PUSH         60
        VM_INVOKE       b_wait_frames, _wait_frames, 1  ; call actor_move_to(), dispose 5 parameter on stack after

        ; Actor Move To
        VM_PUSH         5       ; Actor 5
        VM_PUSH         32      ; X = 32
        VM_PUSH         64      ; Y = 64
        VM_PUSH         0       ; Horizonal movement first
        VM_PUSH         0       ; Don't check collisions
        VM_INVOKE       b_actor_move_to, _actor_move_to, 5  ; call actor_move_to(), dispose 5 parameter on stack after

        VM_JUMP 1$
