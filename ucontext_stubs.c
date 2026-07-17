/* Run-time functions for Modula-2 coroutine implementation.
 * Copyright 2026 Bill Chatfield
 * This file is part of m2c.
 *
 * m2c is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * m2c is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with m2c. If not, see <http://www.gnu.org/licenses/>.
 */

/* This file is a stub implementation of the ucontext functions for OpenBSD.
   These functions are not available on OpenBSD, so we provide empty
   implementations that return an error code.  This allows the rest of the
   code to compile and link, but any attempt to use these functions will
   result in an error. */

#ifdef __OpenBSD__

#include "ucontext_stubs.h"

const int ERROR = -1;

int getcontext(ucontext_t *ucp)
{
    return ERROR;
}

void makecontext(ucontext_t *ucp, void (*func)(), int argc, ...)
{
}

int setcontext(const ucontext_t *ucp)
{
    return ERROR;
}

int swapcontext(ucontext_t *oucp, const ucontext_t *ucp)
{
    return ERROR;
}

#endif
