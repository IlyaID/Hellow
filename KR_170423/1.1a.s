;Task a) У = (x / У) * (x % y)

;y = rbx = 5
;x = rax = 10


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


        mov eax, dword [a]
        mov ebx, dword [b]
        idiv ebx
        add eax, edx


        push eax
        push dword msg1

        call printf
        add esp, 8

        push dword 0
        call exit

ret

section .data

    msg1 : db "%d", 0
    

section .bss
    a resd 1
    b resd 1



