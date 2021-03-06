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

#include <pthreadP.h>
#include <thread.h>

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int thr_keycreate_once (keyp, destructor)
      thread_key_t *keyp;
      void (*destructor)(void *);
{
  int errval = 0;

  if (*keyp)
    {
      errval = __pthread_mutex_lock (&mutex);
      if (errval == 0)
        {
          if (*keyp)
            errval = pthread_key_create (keyp, destructor);

          __pthread_mutex_unlock (&mutex);
        }
    }

  return errval;
}

weak_alias (thr_keycreate_once, pthread_key_create_once_np)
