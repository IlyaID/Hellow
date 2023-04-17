;Task a) У = (x / У) * (x % y)

;y = rbx = 5
;x = rax = 10

mov rax, 10
mov rbx, 5
idiv rbx
add rax, rdx

;rax = У = (x / У) * (x % y)


;Task b) b = (a - 500000) % 10;

;a = rbx = 'A'
mov rdx, 500000
mov rbx, 10
sub rax, rdx
xor rdx, rdx
idiv rbx


;rdx = b = (a - 500000) % 10;

