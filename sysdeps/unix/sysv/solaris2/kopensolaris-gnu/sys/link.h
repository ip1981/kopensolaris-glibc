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

#ifndef _SYS_LINK_H
#define _SYS_LINK_H

#include <link.h>

/* XXX: These are different from OpenSolaris.  */
#define LM_ID_BRAND	-3
#define LM_ID_NONE	-2
#define LM_ID_NEWLM	-1

typedef enum
  {
	RD_NONE = 0,
	RD_PREINIT,
	RD_POSTINIT,
	RD_DLACTIVITY
  } rd_event_e;

typedef enum
  {
	RD_FL_NONE = 0,
	RD_FL_ODBG = 1,
	RD_FL_DBG = 2
  } rd_flags_e;

#endif /* _SYS_LINK_H */
