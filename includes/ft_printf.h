/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:48:19 by mpedrole          #+#    #+#             */
/*   Updated: 2021/11/02 14:50:05 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	process_hex(unsigned long n, const char format);
int	process_u(unsigned long n);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
#endif
