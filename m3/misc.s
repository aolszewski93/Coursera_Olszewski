	.cpu arm7tdmi
	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"misc.c"
	.text
	.global	g5
	.data
	.align	2
	.type	g5, %object
	.size	g5, 40
g5:
	.word	0
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.word	6
	.word	7
	.word	8
	.word	9
	.section	.rodata
	.align	2
.LC0:
	.ascii	"Hello World!\012\000"
	.text
	.align	2
	.global	func
	.syntax unified
	.arm
	.type	func, %function
func:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-8]
	ldr	r3, .L5
	str	r3, [fp, #-12]
	ldr	r3, .L5+4
	ldr	r3, [r3]
	add	r3, r3, #1
	ldr	r2, .L5+4
	str	r3, [r2]
	ldr	r3, .L5+4
	ldr	r3, [r3]
	lsl	r3, r3, #2
	ldr	r2, .L5+8
	add	r3, r3, r2
	ldr	r2, [fp, #-8]
	str	r2, [r3]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L2
.L3:
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-8]
	add	r3, r2, r3
	ldrb	r3, [r3]
	and	r3, r3, #255
	mov	r1, r3
	ldr	r2, .L5+8
	ldr	r3, [fp, #-8]
	str	r1, [r2, r3, lsl #2]
	ldr	r3, .L5+4
	ldr	r3, [r3]
	add	r3, r3, #1
	ldr	r2, .L5+4
	str	r3, [r2]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L2:
	ldr	r3, [fp, #-8]
	cmp	r3, #5
	bls	.L3
	ldr	r3, .L5+4
	ldr	r3, [r3]
	mov	r0, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
.L6:
	.align	2
.L5:
	.word	.LC0
	.word	f2.0
	.word	g5
	.size	func, .-func
	.bss
	.align	2
f2.0:
	.space	4
	.size	f2.0, 4
	.ident	"GCC: (15:14.2.rel1-1) 14.2.1 20241119"
