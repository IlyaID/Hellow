;Task b) b = (a - 500000) % 10;

;a = rbx = 'A'
global main

extern exit
extern puts
extern printf
extern scanf

section .text

    main:
        push dword a
        push dword msg1
        call scanf
        sub esp, 8

        mov edx, 500000
        mov ebx, 10
        sub eax, edx
        xor edx, edx
        idiv ebx


        push eax
        push dword msg2

        call printf
        add esp, 8

        push dword 0
        call exit

ret

section .data

    msg1 : db "%c", 0
    msg2 : db "%d", 0

section .bss
    a resd 1
    b resd 1

