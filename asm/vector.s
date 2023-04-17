# %rax = z
# %rcx = digit

xor %rdx, %rdx
xor %rbx, %rbx

loop_start:
cmp $0,%rcx 
je loop_end
mov (%rax,%rcx,4), %rdx
lea (%rdx,%rdx,1) , %rbx;
dec %rcx
cmp $0,%rcx 
jne loop_start

loop_end:
    ret
