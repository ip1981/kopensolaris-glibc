/* Copyright (C) 2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Modification for FreeBSD contributed by Petr Salinger, 2006.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include <sysdep.h>

/* Usage: long syscall(syscall_number, arg1, arg2, arg3, arg4, arg5, arg6, ...)
   We need to do some arg shifting, the syscall_number will be in rax.  */

	  .text;
ENTRY (__syscall)
    /* We move args in stack, so cannot use rsp - use rbp.  */
    pushq  %rbp; cfi_adjust_cfa_offset(8)
    movq   %rsp, %rbp

    /* Move arguments, just like in subcalls, but in reverse direction.  */
    movq   %rdi, %rax      /* syscall num.  */
    movq   %rsi, %rdi      /* arg #1.  */
    movq   %rdx, %rsi      /* arg #2.  */
    movq   %rcx, %rdx      /* arg #3.  */
    movq   %r8, %r10       /* arg #4.  */
    movq   %r9, %r8        /* arg #5.  */

    /* Arg #6 is on the stack.  */
    movq   16(%rbp), %r9   /* arg #6.  */

    /* First 6 args are in registers, others - in stack.  */
    /* Construct a new call stack frame.  */
    /* XXX Only "mount" has more than 6 args - 8.  */
    movq   32(%rbp), %rcx
    pushq  %rcx; cfi_adjust_cfa_offset(8)  /* arg #8.  */

    movq   24(%rbp), %rcx
    pushq  %rcx; cfi_adjust_cfa_offset(8)  /* arg #7.  */

//    movq   8(%rbp), %rcx
//    pushq  %rcx;
    subq $8, %rsp; cfi_adjust_cfa_offset(8)  /* return addr (intentionally ignored by syscall).  */

    syscall

    /* Restore the stack frame. */
    leave; cfi_adjust_cfa_offset(-32) /* Watch out, we have 4 cfi_adjust_cfa_offset above!  */

	jb SYSCALL_ERROR_LABEL;	/* Jump to error handler if error.  */

L(pseudo_end):
	ret			/* Return to caller.  */
PSEUDO_END (__syscall)
weak_alias (__syscall, syscall)

	  .text;
ENTRY (__systemcall)
	popl %rdx		/* Pop return address into %edx.  */
	popl %rcx		/* Pop sysret_t into %rcx.  */
	popl %eax		/* Pop syscall number into %eax.  */
	pushl %rdx		/* Push return address onto stack.  */
	syscall		/* Do the system call.  */
	pushl %rcx		/* Restore sysret_t on stack.  */
	movl 8(%rsp), %rdx	/* Save return address into %rdx.  */
	pushl %rdx		/* Restore return address on stack.  */
	jb 1f			/* Jump to error handler if error.  */
	movl %rax, 0(%rcx)	/* Set sysret_t.  */
	xorl %rax, %rax		/* Set return to 0.  */
1:
	ret
PSEUDO_END (__syscall)
