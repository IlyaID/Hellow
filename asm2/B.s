global main

extern printf
extern scanf

section .text

    main:
        xor rax, rax
        mov rdi, msg
        mov rsi, a
        call scanf

        mov rax, qword[a]
        and rax, 65535

        mov rdi, msg
        mov rsi, rax

        xor rax, rax

        call printf

        xor rax, rax 

ret

section .data
    msg : db "%d", 0

section .bss
    a resd 1