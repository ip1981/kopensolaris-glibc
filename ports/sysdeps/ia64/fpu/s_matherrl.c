/* Derived from:  */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */


#include <math.h>
#include <math_private.h>
#include "libm_support.h"

int
weak_function
__matherrl(struct exceptionl *x)
{
	int n=0;
	if(x->arg1!=x->arg1) return 0;
	return n;
}
weak_alias (__matherrl, matherrl)
