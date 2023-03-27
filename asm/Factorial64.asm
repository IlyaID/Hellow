mov $0, %rbx;
mov %al, %bl;
mov $1, %rdx;
mov $1, %rax;

cmp $0, %rbx;
je zero
jne loop_start

loop_start:
cmp $0, %rbx
je loop_end
mul %rbx;
dec %rbx;
jne loop_start

loop_end:
mov %rax, %rdx;

zero: