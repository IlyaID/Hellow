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
lea rax, [rbp-0CH] ; 0017 _ 48: 8D. 45, F4
mov rsi, rax ; 001B _ 48: 89. C6
lea rax, [rel ?_003] ; 001E _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 0025 _ 48: 89. C7
mov eax, 0 ; 0028 _ B8, 00000000
call __isoc99_scanf ; 002D _ E8, 00000000(PLT r)
movss xmm1, dword [rbp-0CH] ; 0032 _ F3: 0F 10. 4D, F4
pxor xmm0, xmm0 ; 0037 _ 66: 0F EF. C0
comiss xmm0, xmm1 ; 003B _ 0F 2F. C1
jbe ?_001 ; 003E _ 76, 15
movss xmm0, dword [rbp-0CH] ; 0040 _ F3: 0F 10. 45, F4
movss xmm1, dword [rel ?_004] ; 0045 _ F3: 0F 10. 0D, 00000000(rel)
xorps xmm0, xmm1 ; 004D _ 0F 57. C1
movss dword [rbp-0CH], xmm0 ; 0050 _ F3: 0F 11. 45, F4
?_001: movss xmm0, dword [rbp-0CH] ; 0055 _ F3: 0F 10. 45, F4
pxor xmm2, xmm2 ; 005A _ 66: 0F EF. D2
cvtss2sd xmm2, xmm0 ; 005E _ F3: 0F 5A. D0
movq rax, xmm2 ; 0062 _ 66 48: 0F 7E. D0
movq xmm0, rax ; 0067 _ 66 48: 0F 6E. C0
lea rax, [rel ?_003] ; 006C _ 48: 8D. 05, 00000000(rel)
mov rdi, rax ; 0073 _ 48: 89. C7
mov eax, 1 ; 0076 _ B8, 00000001
call printf ; 007B _ E8, 00000000(PLT r)
mov eax, 0 ; 0080 _ B8, 00000000
mov rdx, qword [rbp-8H] ; 0085 _ 48: 8B. 55, F8
; Note: Address is not rip-relative
; Note: Absolute memory address without relocation
sub rdx, qword [fs:abs 28H] ; 0089 _ 64 48: 2B. 14 25, 00000028
jz ?_002 ; 0092 _ 74, 05
call __stack_chk_fail ; 0094 _ E8, 00000000(PLT r)
?_002: leave ; 0099 _ C9
ret ; 009A _ C3
; main End of function

SECTION .rodata align=16 noexec ; section number 4, const

?_003: ; byte
db 25H, 66H, 00H, 00H, 00H, 00H, 00H, 00H ; 0000 _ %f......
db 00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H ; 0008 _ ........

?_004: dd 80000000H, 00000000H ; 0010 _ -0.0 0.0
dd 00000000H, 00000000H ; 0018 _ 0.0 0.0