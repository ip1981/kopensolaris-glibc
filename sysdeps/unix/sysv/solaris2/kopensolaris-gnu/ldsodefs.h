/* Run-time dynamic linker data structures for loaded ELF shared objects.
   Copyright (C) 2001, 2002, 2003, 2006, 2008 Free Software Foundation, Inc.
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

#ifndef	_LDSODEFS_H

#include <kernel-features.h>

#define PLATFORM_RTLD_GLOBAL_RO_FIELDS          \
    EXTERN const char * _dl_sun_execname;       \
    EXTERN int _dl_malloc_prot_exec;
extern const char * _dl_sun_execname;
extern int _dl_malloc_prot_exec;

/* Since we use __thread in a few places in libc, we need a bit more surplus.  */
#define TLS_STATIC_EXTRA_SURPLUS	4096

/* Get the real definitions.  */
#include_next <ldsodefs.h>

/* Now define our stuff.  */

/* OpenSolaris provides an auxv_t only for dynamic executables.  */
#if defined SHARED || defined IS_IN_rtld
# define HAVE_AUX_VECTOR
# define HAVE_AUX_PAGESIZE
#endif

/* Initialization which is normally done by the dynamic linker.  */
extern void _dl_non_dynamic_init (void) internal_function;

/* We want to enable th rtld_db hooks.  */
#define ENABLE_RTLD_DB

# define DLOPEN_ALLOWED_FLAGS	(RTLD_BINDING_MASK | RTLD_NOLOAD | \
	RTLD_DEEPBIND | RTLD_GLOBAL | RTLD_LOCAL | RTLD_NODELETE)

#endif /* ldsodefs.h */
