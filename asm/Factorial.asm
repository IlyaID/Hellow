mov $0, %ebx;
mov %al, %bl;
mov $1, %edx;
mov $1, %eax;

cmp $0, %ebx;
je zero
jne loop_start

loop_start:
cmp $0, %ebx
je loop_end
mul %ebx;
dec %ebx;
jne loop_start

loop_end:
mov %eax, %edx;

zero: