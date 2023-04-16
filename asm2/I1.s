;Входные данные
;Целое число 0 < N < 10000. Затем N чисел, по модулю не превышающих 216-1, через пробел.
;Выходные данные
;N чисел в обратном порядке.

default rel

global main

extern __stack_chk_fail ; near
extern printf ; near
extern __isoc99_scanf ; near
extern memset ; near

SECTION .text align=1 exec ; section number 1, code

main: ; Function begin
push rbp ; 0000 _ 55
mov rbp, rsp ; 0001 _ 48: 89. E5
sub rsp, 40032 ; 0004 _ 48: 81. EC, 00009C60
; Note: Address is not rip-relative
; Note: Absolute memory address without relocation
mov rax, qword [fs:abs 28H] ; 000B _ 64 48: 8B. 04 25, 00000028
mov qword [rbp-8H], rax ; 0014 _ 48: 89. 45, F8
xor eax, eax ; 0018 _ 31. C0
lea rax, [rbp-9C50H] ; 001A _ 48: 8D. 85, FFFF63B0
mov edx, 40000 ; 0021 _ BA, 00009C40
mov esi, 0 ; 0026 _ BE, 00000000
mov rdi, rax ; 002B _ 48: 89. C7
call memset ; 002E _ E8, 00000000(PLT r)
mov dword [rbp-9C5CH], 0 ; 0033 _ C7. 85, FFFF63A4, 00000000
lea rax, [rbp-9C5CH] ; 003D _ 48: 8D. 85, FFFF63A4
mov rsi, rax ; 0044 _ 48: 89. C6
lea rax, [rel _006] ; 0047 _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 004E _ 48: 89. C7
mov eax, 0 ; 0051 _ B8, 00000000
call __isoc99_scanf ; 0056 _ E8, 00000000(PLT r)
mov dword [rbp-9C58H], 0 ; 005B _ C7. 85, FFFF63A8, 00000000
jmp _002 ; 0065 _ EB, 35

_001: lea rax, [rbp-9C50H] ; 0067 _ 48: 8D. 85, FFFF63B0
mov edx, dword [rbp-9C58H] ; 006E _ 8B. 95, FFFF63A8
movsxd rdx, edx ; 0074 _ 48: 63. D2
shl rdx, 2 ; 0077 _ 48: C1. E2, 02
add rax, rdx ; 007B _ 48: 01. D0
mov rsi, rax ; 007E _ 48: 89. C6
lea rax, [rel _006] ; 0081 _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 0088 _ 48: 89. C7
mov eax, 0 ; 008B _ B8, 00000000
call __isoc99_scanf ; 0090 _ E8, 00000000(PLT r)
add dword [rbp-9C58H], 1 ; 0095 _ 83. 85, FFFF63A8, 01
_002: mov eax, dword [rbp-9C5CH] ; 009C _ 8B. 85, FFFF63A4
cmp dword [rbp-9C58H], eax ; 00A2 _ 39. 85, FFFF63A8
jl _001 ; 00A8 _ 7C, BD
mov eax, dword [rbp-9C5CH] ; 00AA _ 8B. 85, FFFF63A4
sub eax, 1 ; 00B0 _ 83. E8, 01
mov dword [rbp-9C54H], eax ; 00B3 _ 89. 85, FFFF63AC
jmp _004 ; 00B9 _ EB, 2C

_003: mov eax, dword [rbp-9C54H] ; 00BB _ 8B. 85, FFFF63AC
cdqe ; 00C1 _ 48: 98
mov eax, dword [rbp+rax*4-9C50H] ; 00C3 _ 8B. 84 85, FFFF63B0
mov esi, eax ; 00CA _ 89. C6
lea rax, [rel _007] ; 00CC _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 00D3 _ 48: 89. C7
mov eax, 0 ; 00D6 _ B8, 00000000
call printf ; 00DB _ E8, 00000000(PLT r)
sub dword [rbp-9C54H], 1 ; 00E0 _ 83. AD, FFFF63AC, 01
_004: cmp dword [rbp-9C54H], 0 ; 00E7 _ 83. BD, FFFF63AC, 00
jns _003 ; 00EE _ 79, CB
mov eax, 0 ; 00F0 _ B8, 00000000
mov rdx, qword [rbp-8H] ; 00F5 _ 48: 8B. 55, F8
; Note: Address is not rip-relative
; Note: Absolute memory address without relocation
sub rdx, qword [fs:abs 28H] ; 00F9 _ 64 48: 2B. 14 25, 00000028
jz _005 ; 0102 _ 74, 05
call __stack_chk_fail ; 0104 _ E8, 00000000(PLT r)
_005: leave ; 0109 _ C9
ret ; 010A _ C3
; main End of function

SECTION .data align=1 noexec ; section number 2, data

SECTION .bss align=1 noexec ; section number 3, bss

SECTION .rodata align=1 noexec ; section number 4, const

_006: ; byte
db 25H, 64H, 00H ; 0000 _ %d.

_007: ; byte
db 25H, 64H, 20H, 00H ; 0003 _ %d .