/* Copyright 2014 Peter De Wachter
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

#ifndef M2LIB_H
#define M2LIB_H

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h> /* for unlink */

#define FALSE 0
#define TRUE 1

typedef unsigned int Tset;  /* Must match the compiler */

/* m2l_arrpar.c */
extern void m2_arrpar (unsigned char **adr, unsigned int high, unsigned int elong);
/* ml2_assarr.c */
extern void m2_assarr (char *var, char *expr, unsigned int l);
/* m2l_assstr.c */
extern void m2_assstr (char *var, char *str, unsigned int vlong, unsigned int strlong);
/* m2l_cap.c */
extern int m2_cap (unsigned int ch);
/* m2l_cor.c */
extern void m2_newprocess (void (*f) (), int *sp, unsigned int size, int **cor);
extern void m2_transfer (int **cor1, int **cor2);
/* m2l_eq.c */
extern int m2_eq (char *str1, char *str2, unsigned int l);
/* m2l_halt.c */
extern void m2_halt (void);
/* m2l_ne.c */
extern int m2_ne (char *str1, char *str2, unsigned int l);
/* m2l_nites.c */
extern int m2_nites (Tset s1, Tset s2);
/* m2l_rngovf.c */
extern void m2_rngovf (void);
/* m2l_setin.c */
extern int m2_setin (Tset s1, Tset s2);
/* m2l_testptr.c */
extern char *m2_testptr (char *ptr);

#endif
