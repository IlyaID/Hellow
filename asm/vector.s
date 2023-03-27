# %rax = z
# %rcx = digit

xor %rdx, %rdx
xor %rbx, %rbx

loop_start:
cmp $0,%rcx 
je loop_end
movl (%rax,%rcx,8), %rdx
add %rbx, %rdx
jen loop_start

loop_end