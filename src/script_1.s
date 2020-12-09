.include "vm.inc"
        
.globl b_wait_frames, _wait_frames
; .globl b_vm_actor_activate, _vm_actor_activate
; .globl b_vm_actor_set_dir, _vm_actor_set_dir

.area _CODE_3

___bank_SCRIPT_1 = 3
.globl ___bank_SCRIPT_1

_SCRIPT_1::
        VM_LOAD_TEXT            3
        .dw 4, 2, 5
        .asciz "The %tquick%t red\nfox jumps over\nthe lazy brown\n%tdog!"

        VM_OVERLAY_MOVE_TO      0, 12, 1

        VM_DISPLAY_TEXT         1

        VM_OVERLAY_WAIT

        VM_STOP
        ; VM_PUSH         2
        ; VM_INVOKE       b_vm_actor_activate, _vm_actor_activate, 1, -1
        ; VM_PUSH         2
        ; VM_PUSH         64
        ; VM_PUSH         128
        ; VM_PUSH         1
        ; VM_PUSH         0
        ; VM_INVOKE       b_actor_move_to, _actor_move_to, 5, -5
        ; VM_PUSH         2
        ; VM_PUSH         128
        ; VM_PUSH         96
        ; VM_PUSH         1
        ; VM_PUSH         0
        ; VM_INVOKE       b_actor_move_to, _actor_move_to, 5, -5


        ; VM_PUSH         2
        ; VM_PUSH         5
        ; VM_PUSH         6
        ; VM_PUSH         1
        ; VM_PUSH         0        
        ; VM_INVOKE       b_actor_move_to, _actor_move_to, 5, -5


        ; VM_PUSH         
        ; VM_INVOKE       b_vm_actor_activate, _vm_actor_activate, 1, .ARG0

        ; VM_PUSH         60
        ; VM_INVOKE       b_wait_frames, _wait_frames, 1, .ARG0  ; call wait_frames(), dispose 1 parameter on stack after

        ; VM_PUSH         5
        ; VM_INVOKE       b_vm_actor_activate, _vm_actor_activate, 1, .ARG0

        ; VM_PUSH         60
        ; VM_INVOKE       b_wait_frames, _wait_frames, 1, .ARG0  ; call wait_frames(), dispose 1 parameter on stack after

        ; VM_PUSH         7
        ; VM_INVOKE       b_vm_actor_activate, _vm_actor_activate, 0, .ARG0

        ; VM_PUSH         20
        ; VM_INVOKE       b_wait_frames, _wait_frames, 1, .ARG0  ; call wait_frames(), dispose 1 parameter on stack after

        ; VM_PUSH         -1
        ; VM_PUSH         0
        ; VM_INVOKE       b_vm_actor_set_dir, _vm_actor_set_dir, 2, .ARG2

        ; VM_PUSH         20
        ; VM_INVOKE       b_wait_frames, _wait_frames, 1, .ARG0  ; call wait_frames(), dispose 1 parameter on stack after

        ; VM_PUSH         1
        ; VM_PUSH         0
        ; VM_INVOKE       b_vm_actor_set_dir, _vm_actor_set_dir, 2, .ARG2

        ; VM_PUSH         20
        ; VM_INVOKE       b_wait_frames, _wait_frames, 1, .ARG0  ; call wait_frames(), dispose 1 parameter on stack after

        ; VM_PUSH         0
        ; VM_PUSH         1
        ; VM_INVOKE       b_vm_actor_set_dir, _vm_actor_set_dir, 2, .ARG2

        ; VM_PUSH         64
        ; VM_PUSH         128
        ; VM_PUSH         0
        ; VM_PUSH         0                
        ; VM_ACTOR_MOVE_TO .ARG4

        ; VM_POP 4

        ; VM_PUSH         30
        ; VM_INVOKE       b_wait_frames, _wait_frames, 1, .ARG0  ; call wait_frames(), dispose 1 parameter on stack after

        ; VM_PUSH         0
        ; VM_PUSH         -1
        ; VM_INVOKE       b_vm_actor_set_dir, _vm_actor_set_dir, 2, .ARG2

        ; VM_POP 3
    
        VM_STOP
