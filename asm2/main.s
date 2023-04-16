	.text
	.section	.rodata
.LC1:
	.string	"%lf"
.LC2:
	.string	"%lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64	
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	sub	rsp, 32	#,
# main.cpp:6: {
	mov	rax, QWORD PTR fs:40	# tmp92, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR -8[rbp], rax	# D.2854, tmp92
	xor	eax, eax	# tmp92
# main.cpp:7:     double x_0 = 1000.0;
	movsd	xmm0, QWORD PTR .LC0[rip]	# tmp86,
	movsd	QWORD PTR -24[rbp], xmm0	# x_0, tmp86
# main.cpp:9:     scanf("%lf", &x_0);
	lea	rax, -24[rbp]	# tmp87,
	mov	rsi, rax	#, tmp87
	lea	rax, .LC1[rip]	# tmp88,
	mov	rdi, rax	#, tmp88
	mov	eax, 0	#,
	call	__isoc99_scanf@PLT	#
# main.cpp:10:     double sum_milk = getMilk(x_0);
	mov	rax, QWORD PTR -24[rbp]	# x_0.0_1, x_0
	movq	xmm0, rax	#, x_0.0_1
	call	_Z7getMilkd	#
	movq	rax, xmm0	# _7,
	mov	QWORD PTR -16[rbp], rax	# sum_milk, _7
# main.cpp:12:     printf("%lf\n", sum_milk);
	mov	rax, QWORD PTR -16[rbp]	# tmp89, sum_milk
	movq	xmm0, rax	#, tmp89
	lea	rax, .LC2[rip]	# tmp90,
	mov	rdi, rax	#, tmp90
	mov	eax, 1	#,
	call	printf@PLT	#
# main.cpp:14:     return 0;
	mov	eax, 0	# _10,
# main.cpp:15: }
	mov	rdx, QWORD PTR -8[rbp]	# tmp93, D.2854
	sub	rdx, QWORD PTR fs:40	# tmp93, MEM[(<address-space-1> long unsigned int *)40B]
	je	.L3	#,
	call	__stack_chk_fail@PLT	#
.L3:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	_Z7getMilkd
	.type	_Z7getMilkd, @function
_Z7getMilkd:
.LFB1:
	.cfi_startproc
	endbr64	
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	sub	rsp, 48	#,
	movsd	QWORD PTR -40[rbp], xmm0	# x_0, x_0
# main.cpp:19:     double x_current = x_0;
	movsd	xmm0, QWORD PTR -40[rbp]	# tmp90, x_0
	movsd	QWORD PTR -16[rbp], xmm0	# x_current, tmp90
# main.cpp:20:     const double x_cliff = 1.0; 
	movsd	xmm0, QWORD PTR .LC3[rip]	# tmp91,
	movsd	QWORD PTR -8[rbp], xmm0	# x_cliff, tmp91
# main.cpp:21:     double milk = 0.0;
	pxor	xmm0, xmm0	# tmp92
	movsd	QWORD PTR -24[rbp], xmm0	# milk, tmp92
# main.cpp:23:     if((x_current - x_cliff) >= 0.0001)
	movsd	xmm0, QWORD PTR -16[rbp]	# tmp93, x_current
	movsd	xmm1, QWORD PTR .LC3[rip]	# tmp94,
	subsd	xmm0, xmm1	# _1, tmp94
# main.cpp:23:     if((x_current - x_cliff) >= 0.0001)
	comisd	xmm0, QWORD PTR .LC5[rip]	# _1,
	jb	.L5	#,
# main.cpp:25:         milk+=(x_current-1);
	movsd	xmm0, QWORD PTR -16[rbp]	# tmp95, x_current
	movsd	xmm1, QWORD PTR .LC3[rip]	# tmp96,
	subsd	xmm0, xmm1	# _2, tmp96
# main.cpp:25:         milk+=(x_current-1);
	movsd	xmm1, QWORD PTR -24[rbp]	# tmp98, milk
	addsd	xmm0, xmm1	# tmp97, tmp98
	movsd	QWORD PTR -24[rbp], xmm0	# milk, tmp97
# main.cpp:26:         milk+=getMilk(x_current/2);
	movsd	xmm0, QWORD PTR -16[rbp]	# tmp99, x_current
	movsd	xmm1, QWORD PTR .LC6[rip]	# tmp100,
	divsd	xmm0, xmm1	# tmp99, tmp100
	movq	rax, xmm0	# _3, tmp99
	movq	xmm0, rax	#, _3
	call	_Z7getMilkd	#
# main.cpp:26:         milk+=getMilk(x_current/2);
	movsd	xmm1, QWORD PTR -24[rbp]	# tmp102, milk
	addsd	xmm0, xmm1	# tmp101, tmp102
	movsd	QWORD PTR -24[rbp], xmm0	# milk, tmp101
# main.cpp:27:         milk+=getMilk(x_current/3);
	movsd	xmm0, QWORD PTR -16[rbp]	# tmp103, x_current
	movsd	xmm1, QWORD PTR .LC7[rip]	# tmp104,
	divsd	xmm0, xmm1	# tmp103, tmp104
	movq	rax, xmm0	# _4, tmp103
	movq	xmm0, rax	#, _4
	call	_Z7getMilkd	#
# main.cpp:27:         milk+=getMilk(x_current/3);
	movsd	xmm1, QWORD PTR -24[rbp]	# tmp106, milk
	addsd	xmm0, xmm1	# tmp105, tmp106
	movsd	QWORD PTR -24[rbp], xmm0	# milk, tmp105
.L5:
# main.cpp:30:     return milk;
	movsd	xmm0, QWORD PTR -24[rbp]	# _21, milk
	movq	rax, xmm0	# <retval>, _21
# main.cpp:32: }
	movq	xmm0, rax	#, <retval>
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1:
	.size	_Z7getMilkd, .-_Z7getMilkd
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1083129856
	.align 8
.LC3:
	.long	0
	.long	1072693248
	.align 8
.LC5:
	.long	-350469331
	.long	1058682594
	.align 8
.LC6:
	.long	0
	.long	1073741824
	.align 8
.LC7:
	.long	0
	.long	1074266112
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
