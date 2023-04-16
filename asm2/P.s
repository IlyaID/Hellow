default rel

global main
global caw

extern __stack_chk_fail ; near
extern printf ; near
extern __isoc99_scanf ; near

SECTION .text align=1 exec ; section number 1, code

main: ; Function begin
push rbp ; 0000 _ 55
mov rbp, rsp ; 0001 _ 48: 89. E5
sub rsp, 16 ; 0004 _ 48: 83. EC, 10
; Note: Address is not rip-relative
; Note: Absolute memory address without relocation
mov rax, qword [fs:abs 28H] ; 0008 _ 64 48: 8B. 04 25, 00000028
mov qword [rbp-8H], rax ; 0011 _ 48: 89. 45, F8
xor eax, eax ; 0015 _ 31. C0
pxor xmm0, xmm0 ; 0017 _ 66: 0F EF. C0
movss dword [rbp-0CH], xmm0 ; 001B _ F3: 0F 11. 45, F4
lea rax, [rbp-0CH] ; 0020 _ 48: 8D. 45, F4
mov rsi, rax ; 0024 _ 48: 89. C6
lea rax, [rel ?_004] ; 0027 _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 002E _ 48: 89. C7
mov eax, 0 ; 0031 _ B8, 00000000
call __isoc99_scanf ; 0036 _ E8, 00000000(PLT r)
mov eax, dword [rbp-0CH] ; 003B _ 8B. 45, F4
movd xmm0, eax ; 003E _ 66: 0F 6E. C0
call caw ; 0042 _ E8, 00000000(PLT r)
pxor xmm1, xmm1 ; 0047 _ 66: 0F EF. C9
cvtss2sd xmm1, xmm0 ; 004B _ F3: 0F 5A. C8
movq rax, xmm1 ; 004F _ 66 48: 0F 7E. C8
movq xmm0, rax ; 0054 _ 66 48: 0F 6E. C0
lea rax, [rel ?_004] ; 0059 _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 0060 _ 48: 89. C7
mov eax, 1 ; 0063 _ B8, 00000001
call printf ; 0068 _ E8, 00000000(PLT r)
mov eax, 0 ; 006D _ B8, 00000000
mov rdx, qword [rbp-8H] ; 0072 _ 48: 8B. 55, F8
; Note: Address is not rip-relative
; Note: Absolute memory address without relocation
sub rdx, qword [fs:abs 28H] ; 0076 _ 64 48: 2B. 14 25, 00000028
jz ?_001 ; 007F _ 74, 05
call __stack_chk_fail ; 0081 _ E8, 00000000(PLT r)
?_001: leave ; 0086 _ C9
ret ; 0087 _ C3
; main End of function

caw: ; Function begin
push rbp ; 0088 _ 55
mov rbp, rsp ; 0089 _ 48: 89. E5
sub rsp, 16 ; 008C _ 48: 83. EC, 10
movss dword [rbp-4H], xmm0 ; 0090 _ F3: 0F 11. 45, FC
movss xmm0, dword [rel ?_005] ; 0095 _ F3: 0F 10. 05, 00000000(rel)
comiss xmm0, dword [rbp-4H] ; 009D _ 0F 2F. 45, FC
jbe ?_002 ; 00A1 _ 76, 06
pxor xmm0, xmm0 ; 00A3 _ 66: 0F EF. C0
jmp ?_003 ; 00A7 _ EB, 67

?_002: movss xmm0, dword [rbp-4H] ; 00A9 _ F3: 0F 10. 45, FC
movss xmm1, dword [rel ?_005] ; 00AE _ F3: 0F 10. 0D, 00000000(rel)
subss xmm0, xmm1 ; 00B6 _ F3: 0F 5C. C1
movss dword [rbp-8H], xmm0 ; 00BA _ F3: 0F 11. 45, F8
movss xmm0, dword [rbp-4H] ; 00BF _ F3: 0F 10. 45, FC
movss xmm1, dword [rel ?_006] ; 00C4 _ F3: 0F 10. 0D, 00000000(rel)
movaps xmm3, xmm0 ; 00CC _ 0F 28. D8
divss xmm3, xmm1 ; 00CF _ F3: 0F 5E. D9
movd eax, xmm3 ; 00D3 _ 66: 0F 7E. D8
movd xmm0, eax ; 00D7 _ 66: 0F 6E. C0
call caw ; 00DB _ E8, 00000000(PLT r)
movaps xmm4, xmm0 ; 00E0 _ 0F 28. E0
addss xmm4, dword [rbp-8H] ; 00E3 _ F3: 0F 58. 65, F8
movss dword [rbp-8H], xmm4 ; 00E8 _ F3: 0F 11. 65, F8
movss xmm0, dword [rbp-4H] ; 00ED _ F3: 0F 10. 45, FC
movss xmm1, dword [rel ?_007] ; 00F2 _ F3: 0F 10. 0D, 00000000(rel)
divss xmm0, xmm1 ; 00FA _ F3: 0F 5E. C1
movd eax, xmm0 ; 00FE _ 66: 0F 7E. C0
movd xmm0, eax ; 0102 _ 66: 0F 6E. C0
call caw ; 0106 _ E8, 00000000(PLT r)
addss xmm0, dword [rbp-8H] ; 010B _ F3: 0F 58. 45, F8
?_003: leave ; 0110 _ C9
ret ; 0111 _ C3
; caw End of function

SECTION .data align=1 noexec ; section number 2, data

SECTION .bss align=1 noexec ; section number 3, bss

SECTION .rodata align=4 noexec ; section number 4, const

?_004: ; byte
db 25H, 66H, 00H, 00H ; 0000 _ %f..

?_005: dd 3F800000H ; 0004 _ 1.0

?_006: dd 40000000H ; 0008 _ 2.0

?_007: dd 40400000H ; 000C _ 3.0