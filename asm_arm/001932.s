mov x2, 0

loop: 
add x2, x2, 1
sdiv x1, x1, x2 
cmp x1, 1
bne loop