global main

extern exit
extern puts
extern printf
extern scanf

section .text

    main:
        push dword a
        push dword b
        push dword msg1
        call scanf
        sub esp, 8

        xor edx, edx
        xor ebx, ebx
        mov eax, dword [b]
        mov ebx, dword [a]
        cmp eax, ebx
        jl less
        jg more
        je equal
less:

        push eax
        push dword msg2

        call printf
        add esp, 8

        push dword 0
        call exit

ret

more:

        push ebx
        push dword msg2

        call printf
        add esp, 8

        push dword 0
        call exit

ret

equal:

        push ebx
        push dword msg2

        call printf
        add esp, 8

        push dword 0
        call exit

ret

section .data

    msg1 : db "%d%d", 0
    msg2 : db "%d", 0xA, 0


section .bss
    a resd 1
    b resd 1