global main

extern exit
extern puts
extern printf
extern scanf

section .data

    msg1 : db "NO\n", 0xA, 0
    msg2 : db "YES\n", 0xA, 0


section .bss
    a resd 1
    b resd 1

section .text

    main:
        push dword a
        push dword b
        push dword msg1
        call scanf
        sub rsp, 8

        xor rdx, rdx
        xor rbx, rbx
        xor rcx, rcx
        mov rax, dword [b]
        mov rbx, dword [a]
        mov rcx, 0xffffffffffffffff
        add rax, rbx
        cmp rax, rcx
        jl less
        jg more
        je equal
less:

        push dword msg1

        call printf
        add rsp, 8

        push dword 0
        call exit

ret

more:

        push dword msg2

        call printf
        add rsp, 8

        push dword 0
        call exit

ret

equal:

        push dword msg2

        call printf
        add rsp, 8

        push dword 0
        call exit

ret

