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

    subq $8, %rsp; cfi_adjust_cfa_offset(8)  /* return addr (intentionally ignored by syscall).  */

    syscall

    /* Restore the stack frame.  */
    leave; cfi_adjust_cfa_offset(-32) /* Watch out, we have 4 cfi_adjust_cfa_offset above!  */

PSEUDO_END (__syscall)
weak_alias (__syscall, syscall)


	  .text;
/* int __systemcall(sysret_t *, int, ...);  */
ENTRY (__systemcall)
    pushq   %rbp; cfi_adjust_cfa_offset(8)
    movq    %rsp, %rbp
    pushq   %rdi            /* save sysret_t pointer.  */
    movq    %rsi,  %rax     /* syscall num.  */
    movq    %rdx,  %rdi     /* arg #1.  */
    movq    %rcx,  %rsi     /* arg #2.  */
    movq    %r8,   %rdx     /* arg #3.  */
    movq    %r9,   %rcx     /* save arg #4, it should be in %r10.  */
    movq    16(%rbp), %r8   /* arg #5.  */
    movq    24(%rbp), %r9   /* arg #6.  */
    movq    40(%rbp), %r10
    pushq   %r10; cfi_adjust_cfa_offset(8)   /* arg #8, on stack.  */
    movq    32(%rbp), %r10
    pushq   %r10; cfi_adjust_cfa_offset(8)   /* arg #7, on stack.  */
    movq    %rcx, %r10      /* arg #4.  */
    subq    $8,   %rsp; cfi_adjust_cfa_offset(8)  /* return addr (intentionally ignored by syscall).  */

    syscall

    movq    8(%rbp), %r10  /* sysret_t pointer.  */

    /* Restore the stack frame.  */
    leave; cfi_adjust_cfa_offset(-32) /* Watch out, we have 4 cfi_adjust_cfa_offset above!  */

    jb      SYSCALL_ERROR_LABEL;	/* Jump to error handler if error.  */

    movq    %rax, 0(%r10)   /* no error, save result into sysret_t.  */
    movq    %rdx, 8(%r10)
    xorq    %rax, %rax
	ret			/* Return to caller.  */
PSEUDO_END (__systemcall)

