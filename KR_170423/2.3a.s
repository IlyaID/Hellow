;// a
;static unsigned x, y;
;y = 32 * x - x / 8 + x % 16;

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
        mul ecx, 32
        div 8
        mov ebx, eax
        mov eax, dword [a]
        div 16
        mov eax, ecx
        add ecx, ebx
        add ecx, edx
                   

        push ecx
        push dword msg2

        call printf
        add esp, 8

        push dword 0
        call exit

ret

section .data

    msg1 : db "%u", 0
    

section .bss
    a resd 1




v