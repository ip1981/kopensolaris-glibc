/* Compute minimum of two numbers, regarding NaN as missing argument.
   Copyright (C) 2002-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Andreas Jaeger <aj@suse.de>, 2002.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <sysdep.h>

	.text
ENTRY(__fmin)
	ucomisd	%xmm0, %xmm1
	jp	1f		// jump if unordered
	minsd	%xmm1, %xmm0
	jmp	2f

1:	ucomisd	%xmm1, %xmm1	// Is xmm1 a NaN?
	jp	2f		// then return xmm0
	movsd	%xmm1, %xmm0	// otherwise return xmm1

2:	ret
END(__fmin)
weak_alias (__fmin, fmin)
