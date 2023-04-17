;// c
;static int x, y;
;y = x / 64 + x * 4;

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

        xor ecx, ecx
        xor eax, eax
        xor ebx, ebx
        xor edx, edx
        mov ecx, dword [a]
        mov eax, dword [a]
        div 64
        mul ecx, 4
        add ecx, eax
                         

        push ecx
        push dword msg2

        call printf
        add esp, 8

        push dword 0
        call exit

ret

section .data

    msg1 : db "%d", 0
    

section .bss
    a resd 1