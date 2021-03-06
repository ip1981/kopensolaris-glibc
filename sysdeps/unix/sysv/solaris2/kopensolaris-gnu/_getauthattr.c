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

#include <auth_attrP.h>

#define LOOKUP_TYPE	authstr_t
#define SETFUNC_NAME	setauthattr
#define	GETFUNC_NAME	getauthattr
#define	ENDFUNC_NAME	endauthattr
#define DATABASE_NAME	passwd
#define BUFLEN		NSS_BUFLEN_AUTHATTR

#include <nss/getXXent_r.c>

extern int getauthattr_r (authstr_t *, char *, size_t, authstr_t **);


authstr_t * _getauthattr (authstr_t *psbuf, char *buf, int buflen, int *errnop)
{
  authstr_t *psbufp;
  int errval = getauthattr_r (psbuf, buf, buflen, &psbufp);
  if (errval && errnop)
    *errnop = errval;

  return errval ? NULL : psbuf;
}

strong_alias (setauthattr, _setauthattr)
strong_alias (endauthattr, _endauthattr)
