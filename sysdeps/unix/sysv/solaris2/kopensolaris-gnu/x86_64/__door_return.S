/* Copyright (C) 2008 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by David Bartley <dtbartle@csclub.uwaterloo.ca>, 2008.

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
#include "door-offsets.h"

/* The door_return call serves two purposes. First, it is called to transfer
   the results of a door server back to the client. Second, it waits for a
   client to pass in results destined for the server. The first part involves
   no tricks; we simply call into the kernel. When the syscall returns, our
   stack will have been adjusted; client args will have been copied onto the
   stack. The stack pointer itself points to a struct door_results.

   For the second part, we need to pass the door results to the server
   function. The first few fields of door_results matches the arguments of
   the server function (probably by design) so we can just call the server
   function.

   Since servers may block for any reason and to handle high-load doors, we
   create a new server thread whenever there are none in the thread pool.  */

ENTRY (__door_return)
    DO_CALL (door, 6)

    /* syscall returns only in case of error (including EINTR)
       or next door_call() is called.  */

    /* Check for error.  */
    jb SYSCALL_ERROR_LABEL;

    /* After return, rsp points to struct door_resilts (e. i. it is on stack)
       https://github.com/illumos/illumos-gate/blob/master/usr/src/uts/common/fs/doorfs/door_sys.c  */

    /* Check nservers. According to illumos kernel sources it is either 0 or 1.  */
    movl oDOOR_RESULTS_NSERVERS(%rsp), %ecx
    andl %ecx, %ecx
    jg 1f

    /* Create another server thread.  */
    movq oDOOR_RESULTS_DOOR_INFO(%rsp), %rdi /* the first arg to door_server_create_proc().  */
#ifdef PIC
    movq door_server_create_proc@GOTOFF(%rip), %rax
#else
    movq door_server_create_proc, %rax
#endif
    call *%rax

1:
    /* Call server function:
       foo (void *cookie, void *data_ptr, size_t data_size,
            door_desc_t *desc_ptr, uint_t desc_num).  */
    movq oDOOR_RESULTS_COOKIE(%rsp), %rdi
    movq oDOOR_RESULTS_DATA_PTR(%rsp), %rsi
    movq oDOOR_RESULTS_DATA_SIZE(%rsp), %rdx
    movq oDOOR_RESULTS_DESC_PTR(%rsp), %rcx
    movq oDOOR_RESULTS_DESC_NUM(%rsp), %r8

    movq oDOOR_RESULTS_PC(%rsp), %rax
    call *%rax

    /* pthread_exit(NULL):  */
    xorq %rdi, %rdi
    call __pthread_exit

L(pseudo_end):
PSEUDO_END (__door_return)
