/* Prototypes for compatibility double == long double entry points.
   Copyright (C) 2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Jakub Jelinek <jakub@cygnus.com>, 2006.

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

#ifndef __NLDBL_COMPAT_H
#define __NLDBL_COMPAT_H	1

/* Avoid long double prototypes.  */
#define __NO_LONG_DOUBLE_MATH	1
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <printf.h>
#include <wchar.h>
#include <math.h>
#include <monetary.h>
#include <sys/syslog.h>

#define NLDBL_DECL(name) \
  extern __typeof (#name) __nldbl_##name attribute_hidden

NLDBL_DECL (_IO_vfscanf);
NLDBL_DECL (vfscanf);
NLDBL_DECL (vfwscanf);
NLDBL_DECL (obstack_vprintf) __THROW;
NLDBL_DECL (vasprintf) __THROW;
NLDBL_DECL (dprintf);
NLDBL_DECL (vdprintf);
NLDBL_DECL (fprintf);
NLDBL_DECL (vfprintf);
NLDBL_DECL (vfwprintf);
NLDBL_DECL (vsnprintf) __THROW;
NLDBL_DECL (vsprintf) __THROW;
NLDBL_DECL (vsscanf) __THROW;
NLDBL_DECL (vswprintf) __THROW;
NLDBL_DECL (vswscanf) __THROW;
NLDBL_DECL (__asprintf);
NLDBL_DECL (asprintf);
NLDBL_DECL (__printf_fp);
NLDBL_DECL (printf_size) __THROW;
NLDBL_DECL (syslog);
NLDBL_DECL (vsyslog);
NLDBL_DECL (qecvt);
NLDBL_DECL (qfcvt);
NLDBL_DECL (qgcvt);
extern int __nldbl___vfprintf_chk (FILE *__restrict, int,
				   const char *__restrict, _G_va_list)
  attribute_hidden;
extern int __nldbl___vfwprintf_chk (FILE *__restrict, int,
				    const wchar_t *__restrict, __gnuc_va_list)
  attribute_hidden;
extern int __nldbl___vsprintf_chk (char *__restrict, int, size_t,
				   const char *__restrict, _G_va_list) __THROW
  attribute_hidden;
extern int __nldbl___vsnprintf_chk (char *__restrict, size_t, int, size_t,
				    const char *__restrict, _G_va_list)
  __THROW attribute_hidden;
extern int __nldbl___vswprintf_chk (wchar_t *__restrict, size_t, int, size_t,
				    const wchar_t *__restrict, __gnuc_va_list)
  __THROW attribute_hidden;
extern void __nldbl___vsyslog_chk (int, int, const char *, va_list)
  attribute_hidden;
extern ssize_t __nldbl___vstrfmon (char *, size_t, const char *, va_list)
  __THROW attribute_hidden;
extern ssize_t  __nldbl___vstrfmon_l (char *, size_t, __locale_t,
				      const char *, va_list)
  __THROW attribute_hidden;


#endif /* __NLDBL_COMPAT_H */