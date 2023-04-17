;// b
;static long long x;
;x *= 2;

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
        sub rsp, 8

        xor rax, rcx
        mov rax, dword [a]
        mul rax, 2
                           

        push rax
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
    

