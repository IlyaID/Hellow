global main

;Объявляем используемые внешние функции из libc
extern exit
extern puts
extern scanf
extern printf

;Сегмент кода:
section .text
 
;Функция main:
main:
 
;Параметры передаются в стеке:

 
;По конвенции Си вызывающая процедура должна
;очищать стек от параметров самостоятельно:

 
push dword a
push dword b
push dword msg1
call scanf
sub esp, 8

mov eax, dword [b]
mov edx, dword [a]
cmp eax, edx
cmovge eax, edx
 
push eax
push dword msg2
 
call printf
add esp, 8
 
;Завершение программы с кодом выхода 0:
push dword 0
call exit
 
ret
 
;Сегмент инициализированных данных
section .data

msg1 : db "%d%d",0
msg2 : db "%d", 0xA, 0
 
; Сегмент неинициализированных данных
section .bss
a resd 1
b resd 1