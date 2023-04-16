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

        xor ebx, ebx
        xor ecx, ecx
        xor edx, edx

        mov ecx, dword [a]
        mov ebx, dword [a]
        mov edx, dword [a]
        
        cmp ecx, 1
        cmp ebx, 1
        cmp edx, 1
        

        push eax
        push dword msg2

        call printf
        add esp, 8

        push dword 0
        call exit

ret

section .data

    msg1 : db "%d", 0
    msg2 : db "%d", 0xA, 0


section .bss
    a resd 1
    b resd 1