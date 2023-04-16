default rel

global main

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
lea rdx, [rbp-0CH] ; 0017 _ 48: 8D. 55, F4
lea rax, [rbp-10H] ; 001B _ 48: 8D. 45, F0
mov rsi, rax ; 001F _ 48: 89. C6
lea rax, [rel ?_002] ; 0022 _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 0029 _ 48: 89. C7
mov eax, 0 ; 002C _ B8, 00000000
call __isoc99_scanf ; 0031 _ E8, 00000000(PLT r)
mov eax, dword [rbp-10H] ; 0036 _ 8B. 45, F0
pxor xmm0, xmm0 ; 0039 _ 66: 0F EF. C0
cvtsi2ss xmm0, eax ; 003D _ F3: 0F 2A. C0
mov eax, dword [rbp-0CH] ; 0041 _ 8B. 45, F4
pxor xmm1, xmm1 ; 0044 _ 66: 0F EF. C9
cvtsi2ss xmm1, eax ; 0048 _ F3: 0F 2A. C8
divss xmm0, xmm1 ; 004C _ F3: 0F 5E. C1
pxor xmm2, xmm2 ; 0050 _ 66: 0F EF. D2
cvtss2sd xmm2, xmm0 ; 0054 _ F3: 0F 5A. D0
movq rax, xmm2 ; 0058 _ 66 48: 0F 7E. D0
movq xmm0, rax ; 005D _ 66 48: 0F 6E. C0
lea rax, [rel ?_003] ; 0062 _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 0069 _ 48: 89. C7
mov eax, 1 ; 006C _ B8, 00000001
call printf ; 0071 _ E8, 00000000(PLT r)
mov eax, 0 ; 0076 _ B8, 00000000
mov rdx, qword [rbp-8H] ; 007B _ 48: 8B. 55, F8
; Note: Address is not rip-relative
; Note: Absolute memory address without relocation
sub rdx, qword [fs:abs 28H] ; 007F _ 64 48: 2B. 14 25, 00000028
jz ?_001 ; 0088 _ 74, 05
call __stack_chk_fail ; 008A _ E8, 00000000(PLT r)
?_001: leave ; 008F _ C9
ret ; 0090 _ C3
; main End of function

SECTION .data align=1 noexec ; section number 2, data

SECTION .bss align=1 noexec ; section number 3, bss

SECTION .rodata align=1 noexec ; section number 4, const

?_002: ; byte
db 25H, 64H, 25H, 64H, 00H ; 0000 _ %d%d.

?_003: ; byte
db 25H, 66H, 00H ; 0005 _ %f.