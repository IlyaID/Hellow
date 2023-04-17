section .bss
    buf resb 1

section .text
    global _start

    _start: 
        mov eax, 3
        mov ebx, 0
        mov ecx, buf
        mov edx, 1
        int 0x80

        mov al, [buf]
        or al, 7
        mov [buf], al

        mov eax, 4
        mov ebx, 1
        mov ecx, buf
        mov edx, 1
        int 0x80

        mov rax, 0x3C
        mov rdi, 0
        call 


