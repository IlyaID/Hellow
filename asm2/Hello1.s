global main

extern puts 
extern exit

section .text
main:

push dword msg
call puts
sub esp, 4

push dword 0
call exit

ret

section .data
msg: db "Liberté, égalité, fraternité!", 0xA, 0