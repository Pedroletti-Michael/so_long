#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	process_hex(unsigned long long n, const char format);
int	process_p(unsigned long long n);
int	process_u(unsigned long long n);
#endif
