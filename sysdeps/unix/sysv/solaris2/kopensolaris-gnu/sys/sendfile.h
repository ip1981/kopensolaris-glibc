/* sendfile -- copy data directly from one file descriptor to another
   Copyright (C) 1998,99,01,2002,2004,2008 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

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

#ifndef _SYS_SENDFILE_H
#define _SYS_SENDFILE_H	1

#include <features.h>
#include <sys/types.h>

#define SENDFILEV	0
#define SENDFILEV64	1

#define SFV_FD_SELF	(-2)

typedef struct sendfilevec
{
	int sfv_fd;
	unsigned int sfv_flag;
	off_t sfv_off;
	size_t sfv_len;
} sendfilevec_t;

#ifdef __USE_LARGEFILE64
typedef struct sendfilevec64
{
	int sfv_fd;
	unsigned int sfv_flag;
	off64_t sfv_off;
	size_t sfv_len;
} sendfilevec64_t;
#endif

__BEGIN_DECLS

/* Send up to COUNT bytes from file associated with IN_FD starting at
   *OFFSET to descriptor OUT_FD.  Set *OFFSET to the IN_FD's file position
   following the read bytes.  If OFFSET is a null pointer, use the normal
   file position instead.  Return the number of written bytes, or -1 in
   case of error.  */
#ifndef __USE_FILE_OFFSET64
extern ssize_t sendfile (int __out_fd, int __in_fd, off_t *__offset,
			 size_t __count) __THROW;
#else
# ifdef __REDIRECT_NTH
extern ssize_t __REDIRECT_NTH (sendfile,
			       (int __out_fd, int __in_fd, __off64_t *__offset,
				size_t __count), sendfile64);
# else
#  define sendfile sendfile64
# endif
#endif
#ifdef __USE_LARGEFILE64
extern ssize_t sendfile64 (int __out_fd, int __in_fd, __off64_t *__offset,
			   size_t __count) __THROW;
#endif

#ifndef __USE_FILE_OFFSET64
extern ssize_t sendfilev (int, const sendfilevec_t *,
			   int, size_t *) __THROW;
#else
# ifdef __REDIRECT_NTH
extern ssize_t __REDIRECT_NTH (sendfilev,
			       (int, const sendfilevec64_t *, int, size_t *), sendfilev64);
# else
#  define sendfilev sendfilev64
# endif
#endif
#ifdef __USE_LARGEFILE64
extern ssize_t sendfilev64 (int, const sendfilevec64_t *,
			   int, size_t *) __THROW;
#endif

__END_DECLS

#endif	/* sys/sendfile.h */
