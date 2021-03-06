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

#ifndef _UADMINP_H
#define _UADMINP_H

#include <sys/types.h>

/* uadmin cmd's.  */
#define	A_REBOOT	1
#define	A_SHUTDOWN	2
#define	A_FREEZE	3
#define	A_REMOUNT	4
#define	A_DUMP		5
#define	A_FTRACE	15
#define	A_SWAPCTL	16
#define A_SDTTEST	22

/* Shutdown-related fcn's.  */
#define	AD_HALT		0
#define	AD_BOOT		1
#define	AD_IBOOT	2
#define	AD_SBOOT	3
#define	AD_SIBOOT	4
#define	AD_POWEROFF	6
#define	AD_NOSYNC	7
#define AD_FASTREBOOT	8
#define AD_FASTREBOOT_DRYRUN	9

/* Freeze-related fcn's.  */
#define AD_COMPRESS	0
#define AD_FORCE	1
#define AD_CHECK	2
#define AD_REUSEINIT	3
#define AD_REUSABLE	4
#define AD_REUSEFINI	5
#define AD_SUSPEND_TO_DISK	AD_COMPRESS
#define AD_CHECK_SUSPEND_TO_DISK	AD_CHECK
#define AD_SUSPEND_TO_RAM	20
#define AD_CHECK_SUSPEND_TO_RAM	21

#define AD_FTRACE_START	1
#define AD_FTRACE_STOP	2

#define BOOTARGS_MAX	256

extern int uadmin (int, int, uintptr_t);

#endif /* _UADMINP_H */
