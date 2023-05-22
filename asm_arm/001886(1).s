mov w0, 1
mov w2, 1
and w1, w1, 255

.loop: 
mul w2, w0, w2
add w0, w0,  1
cmp w0, w1
ble .loop

