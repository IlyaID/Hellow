;Отсортируйте целые числа по неубыванию
;Входные данные
;Целое число 0 < N < 10000. Затем N чисел, по модулю не превышающих 216-1, через пробел.
;Выходные данные
;N чисел в порядке неубывания .

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
sub rsp, 40048 ; 0004 _ 48: 81. EC, 00009C70
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
mov dword [rbp-9C68H], 0 ; 0033 _ C7. 85, FFFF6398, 00000000
lea rax, [rbp-9C68H] ; 003D _ 48: 8D. 85, FFFF6398
mov rsi, rax ; 0044 _ 48: 89. C6
lea rax, [rel ?_011] ; 0047 _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 004E _ 48: 89. C7
mov eax, 0 ; 0051 _ B8, 00000000
call __isoc99_scanf ; 0056 _ E8, 00000000(PLT r)
mov dword [rbp-9C64H], 0 ; 005B _ C7. 85, FFFF639C, 00000000
jmp ?_002 ; 0065 _ EB, 35

?_001: lea rax, [rbp-9C50H] ; 0067 _ 48: 8D. 85, FFFF63B0
mov edx, dword [rbp-9C64H] ; 006E _ 8B. 95, FFFF639C
movsxd rdx, edx ; 0074 _ 48: 63. D2
shl rdx, 2 ; 0077 _ 48: C1. E2, 02
add rax, rdx ; 007B _ 48: 01. D0
mov rsi, rax ; 007E _ 48: 89. C6
lea rax, [rel ?_011] ; 0081 _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 0088 _ 48: 89. C7
mov eax, 0 ; 008B _ B8, 00000000
call __isoc99_scanf ; 0090 _ E8, 00000000(PLT r)
add dword [rbp-9C64H], 1 ; 0095 _ 83. 85, FFFF639C, 01
?_002: mov eax, dword [rbp-9C68H] ; 009C _ 8B. 85, FFFF6398
cmp dword [rbp-9C64H], eax ; 00A2 _ 39. 85, FFFF639C
jl ?_001 ; 00A8 _ 7C, BD
mov dword [rbp-9C60H], 0 ; 00AA _ C7. 85, FFFF63A0, 00000000
jmp ?_007 ; 00B4 _ E9, 000000A4

?_003: mov eax, dword [rbp-9C68H] ; 00B9 _ 8B. 85, FFFF6398
sub eax, 2 ; 00BF _ 83. E8, 02
mov dword [rbp-9C5CH], eax ; 00C2 _ 89. 85, FFFF63A4
jmp ?_006 ; 00C8 _ EB, 7A

?_004: mov eax, dword [rbp-9C5CH] ; 00CA _ 8B. 85, FFFF63A4
cdqe ; 00D0 _ 48: 98
mov edx, dword [rbp+rax*4-9C50H] ; 00D2 _ 8B. 94 85, FFFF63B0
mov eax, dword [rbp-9C5CH] ; 00D9 _ 8B. 85, FFFF63A4
add eax, 1 ; 00DF _ 83. C0, 01
cdqe ; 00E2 _ 48: 98
mov eax, dword [rbp+rax*4-9C50H] ; 00E4 _ 8B. 84 85, FFFF63B0
cmp edx, eax ; 00EB _ 39. C2
jle ?_005 ; 00ED _ 7E, 4E
mov eax, dword [rbp-9C5CH] ; 00EF _ 8B. 85, FFFF63A4
cdqe ; 00F5 _ 48: 98
mov eax, dword [rbp+rax*4-9C50H] ; 00F7 _ 8B. 84 85, FFFF63B0
mov dword [rbp-9C54H], eax ; 00FE _ 89. 85, FFFF63AC
mov eax, dword [rbp-9C5CH] ; 0104 _ 8B. 85, FFFF63A4
add eax, 1 ; 010A _ 83. C0, 01
cdqe ; 010D _ 48: 98
mov edx, dword [rbp+rax*4-9C50H] ; 010F _ 8B. 94 85, FFFF63B0
mov eax, dword [rbp-9C5CH] ; 0116 _ 8B. 85, FFFF63A4
cdqe ; 011C _ 48: 98
mov dword [rbp+rax*4-9C50H], edx ; 011E _ 89. 94 85, FFFF63B0
mov eax, dword [rbp-9C5CH] ; 0125 _ 8B. 85, FFFF63A4
add eax, 1 ; 012B _ 83. C0, 01
cdqe ; 012E _ 48: 98
mov edx, dword [rbp-9C54H] ; 0130 _ 8B. 95, FFFF63AC
mov dword [rbp+rax*4-9C50H], edx ; 0136 _ 89. 94 85, FFFF63B0
?_005: sub dword [rbp-9C5CH], 1 ; 013D _ 83. AD, FFFF63A4, 01
?_006: mov eax, dword [rbp-9C5CH] ; 0144 _ 8B. 85, FFFF63A4
cmp eax, dword [rbp-9C60H] ; 014A _ 3B. 85, FFFF63A0
jge ?_004 ; 0150 _ 0F 8D, FFFFFF74
add dword [rbp-9C60H], 1 ; 0156 _ 83. 85, FFFF63A0, 01
?_007: mov eax, dword [rbp-9C68H] ; 015D _ 8B. 85, FFFF6398
cmp dword [rbp-9C60H], eax ; 0163 _ 39. 85, FFFF63A0
jl ?_003 ; 0169 _ 0F 8C, FFFFFF4A
mov dword [rbp-9C58H], 0 ; 016F _ C7. 85, FFFF63A8, 00000000
jmp ?_009 ; 0179 _ EB, 2C

?_008: mov eax, dword [rbp-9C58H] ; 017B _ 8B. 85, FFFF63A8
cdqe ; 0181 _ 48: 98
mov eax, dword [rbp+rax*4-9C50H] ; 0183 _ 8B. 84 85, FFFF63B0
mov esi, eax ; 018A _ 89. C6
lea rax, [rel ?_012] ; 018C _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 0193 _ 48: 89. C7
mov eax, 0 ; 0196 _ B8, 00000000
call printf ; 019B _ E8, 00000000(PLT r)
add dword [rbp-9C58H], 1 ; 01A0 _ 83. 85, FFFF63A8, 01
?_009: mov eax, dword [rbp-9C68H] ; 01A7 _ 8B. 85, FFFF6398
cmp dword [rbp-9C58H], eax ; 01AD _ 39. 85, FFFF63A8
jl ?_008 ; 01B3 _ 7C, C6
mov eax, 0 ; 01B5 _ B8, 00000000
mov rdx, qword [rbp-8H] ; 01BA _ 48: 8B. 55, F8
; Note: Address is not rip-relative
; Note: Absolute memory address without relocation
sub rdx, qword [fs:abs 28H] ; 01BE _ 64 48: 2B. 14 25, 00000028
jz ?_010 ; 01C7 _ 74, 05
call __stack_chk_fail ; 01C9 _ E8, 00000000(PLT r)
?_010: leave ; 01CE _ C9
ret ; 01CF _ C3
; main End of function

SECTION .data align=1 noexec ; section number 2, data

SECTION .bss align=1 noexec ; section number 3, bss

SECTION .rodata align=1 noexec ; section number 4, const

?_011: ; byte
db 25H, 64H, 00H ; 0000 _ %d.

?_012: ; byte
db 25H, 64H, 20H, 00H ; 0003 _ %d .