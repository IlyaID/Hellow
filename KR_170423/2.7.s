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

        xor eax, eax
        mov eax, dword [a]
        div eax, 1
        
    L:
        push eax
        push dword msg2

        call printf
        add rsp, 8

        push dword 0
        call exit

ret

section .data

    msg1 : db "%lld", 0
    

section .bss
    a resd 1
    