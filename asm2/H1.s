;Напишите программу, вычисляющую наименьшее общее кратное двух чисел.


default rel

global main

extern __stack_chk_fail ; near
extern printf ; near
extern __isoc99_scanf ; near

SECTION .text align=1 exec ; section number 1, code

main: ; Function begin
push rbp ; 0000 _ 55
mov rbp, rsp ; 0001 _ 48: 89. E5
sub rsp, 32 ; 0004 _ 48: 83. EC, 20
; Note: Address is not rip-relative
; Note: Absolute memory address without relocation
mov rax, qword [fs:abs 28H] ; 0008 _ 64 48: 8B. 04 25, 00000028
mov qword [rbp-8H], rax ; 0011 _ 48: 89. 45, F8
xor eax, eax ; 0015 _ 31. C0
lea rdx, [rbp-14H] ; 0017 _ 48: 8D. 55, EC
lea rax, [rbp-18H] ; 001B _ 48: 8D. 45, E8
mov rsi, rax ; 001F _ 48: 89. C6
lea rax, [rel ?_005] ; 0022 _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 0029 _ 48: 89. C7
mov eax, 0 ; 002C _ B8, 00000000
call __isoc99_scanf ; 0031 _ E8, 00000000(PLT r)
mov edx, dword [rbp-14H] ; 0036 _ 8B. 55, EC
mov eax, dword [rbp-18H] ; 0039 _ 8B. 45, E8
imul eax, edx ; 003C _ 0F AF. C2
mov dword [rbp-10H], eax ; 003F _ 89. 45, F0
mov eax, dword [rbp-10H] ; 0042 _ 8B. 45, F0
mov dword [rbp-0CH], eax ; 0045 _ 89. 45, F4
jmp ?_003 ; 0048 _ EB, 28

?_001: mov ecx, dword [rbp-18H] ; 004A _ 8B. 4D, E8
mov eax, dword [rbp-0CH] ; 004D _ 8B. 45, F4
cdq ; 0050 _ 99
idiv ecx ; 0051 _ F7. F9
mov eax, edx ; 0053 _ 89. D0
test eax, eax ; 0055 _ 85. C0
jnz ?_002 ; 0057 _ 75, 15
mov ecx, dword [rbp-14H] ; 0059 _ 8B. 4D, EC
mov eax, dword [rbp-0CH] ; 005C _ 8B. 45, F4
cdq ; 005F _ 99
idiv ecx ; 0060 _ F7. F9
mov eax, edx ; 0062 _ 89. D0
test eax, eax ; 0064 _ 85. C0
jnz ?_002 ; 0066 _ 75, 06
mov eax, dword [rbp-0CH] ; 0068 _ 8B. 45, F4
mov dword [rbp-10H], eax ; 006B _ 89. 45, F0
?_002: sub dword [rbp-0CH], 1 ; 006E _ 83. 6D, F4, 01
?_003: cmp dword [rbp-0CH], 0 ; 0072 _ 83. 7D, F4, 00
jg ?_001 ; 0076 _ 7F, D2
mov eax, dword [rbp-10H] ; 0078 _ 8B. 45, F0
mov esi, eax ; 007B _ 89. C6
lea rax, [rel ?_006] ; 007D _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 0084 _ 48: 89. C7
mov eax, 0 ; 0087 _ B8, 00000000
call printf ; 008C _ E8, 00000000(PLT r)
mov eax, 0 ; 0091 _ B8, 00000000
mov rdx, qword [rbp-8H] ; 0096 _ 48: 8B. 55, F8
; Note: Address is not rip-relative
; Note: Absolute memory address without relocation
sub rdx, qword [fs:abs 28H] ; 009A _ 64 48: 2B. 14 25, 00000028
jz ?_004 ; 00A3 _ 74, 05
call __stack_chk_fail ; 00A5 _ E8, 00000000(PLT r)
?_004: leave ; 00AA _ C9
ret ; 00AB _ C3
; main End of function

SECTION .data align=1 noexec ; section number 2, data

SECTION .bss align=1 noexec ; section number 3, bss

SECTION .rodata align=1 noexec ; section number 4, const

?_005: ; byte
db 25H, 64H, 25H, 64H, 00H ; 0000 _ %d%d.

?_006: ; byte
db 25H, 64H, 0AH, 00H ; 0005 _ %d..