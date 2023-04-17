;static char a;
;static short b;

global main

extern exit
extern puts
extern printf
extern scanf

section .text

    main:

        push byte a
        push dword msg1
        call scanf
        sub esp, 8

        xor ebx, ebx 
        xor eax, eax
        mov al, byte [a]
        mov bl, al
       
        push bx
        push dword msg2

        call printf
        add esp, 8

        push dword 0
        call exit

ret

section .data

    msg1 : db "%c", 0
    msg2 : db "%u", 0

section .bss
    a resd 1
    b resd 1