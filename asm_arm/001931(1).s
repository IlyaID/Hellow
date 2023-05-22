mov w2, 0

loop: 
add w2, w2, 1
sdiv w1, w1, w2 
cmp w1, 1
bne loop