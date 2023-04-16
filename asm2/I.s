
;Входные данные
;Целое число 0 < N < 10000. Затем N чисел, по модулю не превышающих 216-1, через пробел.
;Выходные данные
;N чисел в обратном порядке.

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
        add esp, 8

        xor eax, eax
        xor ebx, ebx
        xor edx, edx
        xor ecx, ecx

        mov eax, dword [a]
        mov ebx, dword [a]
        mov ebp, esp
        mov ecx, esp
        cmp eax, 0
        je loop_print
        jne loop_scan

loop_scan:       
        push ecx
        push dword msg1
        call scanf
        sub ecx, 8
        dec eax
        cmp eax, 0
        jne loop_scan
        je loop_print

loop_print:
        call printf
        add esp, 8
        dec ebx
        cmp ebx, 0
        jne loop_print
        je end

end:
        push dword 0
        call exit

section .data

    msg1 : db "%d", 0
    
section .bss
    a resd 1
    