mov $0, %edx;
mov $1, %ebx;

cmp $1, %eax
jne loop_start
je loop_end

loop_start:
xor %edx, %edx
inc %ebx;
div %ebx;
cmp $1, %eax
jne loop_start

je loop_end

loop_end: