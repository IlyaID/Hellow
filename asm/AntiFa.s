mov $0, %edx;
mov %al, %dl;
mov $1, %ebx;
mov %eax, %edx;

cmp $1, %eax
jne loop_start
je loop_end

loop_start:
inc %ebx;
div %ebx;
cmp $1, %eax
jne loop_start

je loop_end

loop_end:
mov %eax, %ebx;