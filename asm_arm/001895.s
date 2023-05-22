mov x0, 1
mov x2, 1
and x1, x1, 255

.loop: 
mul x2, x0, x2
add x0, x0,  1
cmp x0, x1
ble .loop