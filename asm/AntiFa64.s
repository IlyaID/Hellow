mov $0, %rdx;
mov $1, %rbx;

cmp $1, %rax
jne loop_start
je loop_end

loop_start:
xor %rdx, %rdx
inc %rbx;
div %rbx;
cmp $1, %rax
jne loop_start

je loop_end

loop_end: