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

#ifndef _EXEC_ATTRP_H
#define _EXEC_ATTRP_H

#include <sys/types.h>
#include <nss/nss.h>

#define NSS_BUFLEN_USERATTR	1024

typedef struct execstr_s
  {
	char *name;
	char *policy;
	char *type;
	char *res1;
	char *res2;
	char *id;
	char *attr;
	struct execstr_s *next;
  } execstr_t;

struct parser_data;
extern int _nss_files_parse_execattr (char *line, struct execstr_s *result,
				   struct parser_data *data,
				   size_t datalen, int *errnop);
libnss_files_hidden_proto (_nss_files_parse_execattr)

#endif /* _EXEC_ATTRP_H */
