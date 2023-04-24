// we don't need code starting from 149 to 174
    .global outb
outb:
	stp x29, x30, [sp, -16]! // save frame pointer and RA on stack
	mov x29, sp
    ldr w1, x1
    strb w1, [x0]
	ldp x29, x30, [sp], 16
	ret

    // out long, which is 8 bytes in 64 bit mode.
    .global outl
outl:
	stp x29, x30, [sp, -16]! // save frame pointer and RA on stack
	mov x29, sp
    str x1, [x0]
	ldp x29, x30, [sp], 16
	ret