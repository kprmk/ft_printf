#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//
#include <stdio.h>
//
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int     ft_printf(const char *format, ...);

int     is_even(const char *format, int i);
char    *count_args(const char *format, int *amount);
#endif