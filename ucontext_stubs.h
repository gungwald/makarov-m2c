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

#ifndef MAKAROV_M2C_UCONTEXT_OPENBSD_H
#define MAKAROV_M2C_UCONTEXT_OPENBSD_H

#include <stddef.h> /* for size_t */

typedef struct {
        void *ss_sp;
        size_t ss_size;
        int ss_flags;
} ucontext_stack_t;

typedef struct ucontext
{
    unsigned long uc_flags;
    struct ucontext *uc_link;
    ucontext_stack_t uc_stack;
} ucontext_t;

extern int getcontext(ucontext_t *ucp);
extern int setcontext(const ucontext_t *ucp);
extern void makecontext(ucontext_t *ucp, void (*func)(), int argc, ...);
extern int swapcontext(ucontext_t *oucp, const ucontext_t *ucp);

#endif
