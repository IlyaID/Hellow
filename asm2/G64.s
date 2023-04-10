section .text
    default rel
    extern puts
    extern scanf
    global main

    main:
        push rbp
       
        lea rdx, [buf]
        add rdx, 0x8
        lea rsi, [buf]
        lea rdi, [format]
        xor eax, eax
        call scanf wrt ..plt
        
        mov rax, [buf]
        mov rbx, [buf+0x8]
        add rax, rbx

        jc load_yes
        lea rdi, [no]
        jmp output
        
load_yes:     
        lea rdi, [yes]
        
output:
        call puts wrt ..plt

        pop rbp
        xor rax, rax
        ret



section .data
    format db "%llu %llu", 0x0
    yes db "YES", 0x0
    no db "NO", 0x0
    buf dq 0,0


