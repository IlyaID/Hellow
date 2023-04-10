section .data
    fmt_s: db "%u", 0
    fmt_p: db "%u ", 0

section .bss

    arr1 resq 8 
    arr2 resq 8 

global main
extern printf
extern scanf
extern exit

section .text

main:
        mov rbx, arr1
        mov r12, 0
        mov r13, 8

back1:
        mov rdi, fmt_s
        lea rsi, [rbx+r12*8]
        mov rax, 0
        call scanf
        add r12, 1
        cmp r12, r13
        jl back1

        mov rbx, arr2
        mov r12, 0 
        mov r13, 8
    
back2:
        mov rdi, fmt_s
        lea rsi, [rbx+r12*8]
        mov rax, 0
        call scanf
        add r12, 1
        cmp r12, r13
        jl back2

        mov rbx, arr1
        mov rcx, arr2
        mov r12, 0
        mov r13, 8

back3:
        mov r8, [rbx+r12*8]
        add r8, [rcx+r12*8]
        cmp r8, 127
        jbe ifend
        mov r8, 127
        jmp ifend

ifend:
        mov [rbx+r12*8], r8

        add r12, 1
        cmp r12, r13
        jl back3

        mov rbx, arr1
        mov r12, 0
        mov r13, 8

back4:
        mov rdi, fmt_p
        mov rsi, [rbx+r12*8]
        mov rax, 0
        call printf
        add r12, 1
        cmp r12, r13
        jl back4

        xor rax, rax
        xor rdi, rdi
        call exit

        xor rax, rax
        ret