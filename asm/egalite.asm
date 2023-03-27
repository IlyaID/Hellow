cmp %ax, %bx;
mov $0,%dx;
jne not_equal
je equal
equal:
mov $1,%dx;
not_equal: 