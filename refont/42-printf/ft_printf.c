/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:57:41 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/27 13:03:02 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"


int  is_an_arg(const char a, const char b)
{
    if (a == '%' && (b == 'c' || b == 's' || b == 'p' || b == 'd'
        || b == 'i' || b == 'u' || b == 'x' || b == 'X' || b == '%'))
        return (b);
    return (0);
}

int process_arg(const char c1, const char c2, va_list ap)
{
    unsigned long   a;
    int             nb_c;

    nb_c = 0;
    if (is_an_arg(c1, c2) == '%')
        nb_c += ft_putchar_fd('%', 1);
    else
    {
        a = va_arg(ap, unsigned long);
        if (is_an_arg(c1, c2) == 'c')
            nb_c += ft_putchar_fd((char)a, 1);
        else if (is_an_arg(c1, c2) == 's')
            nb_c += ft_putstr_fd((char *)a, 1);
        else if (is_an_arg(c1, c2) == 'd' || is_an_arg(c1, c2) == 'i')
            nb_c += ft_putnbr_fd((int)a, 1);
        else if (is_an_arg(c1, c2) == 'u')
            nb_c += process_u((unsigned long long) a);
        else if (is_an_arg(c1, c2) == 'X' || is_an_arg(c1, c2) == 'x')
            nb_c += process_hex((unsigned long long) a, c2);
        else if (is_an_arg(c1, c2) == 'p')
            nb_c += process_hex((unsigned long long) a, 'x');
    }
    return (nb_c); // retourner la bonne valeur, c'est a dire le nombre de char ecrit
}

int ft_printf(const char *str, ...)
{
    va_list ap;
    int     i;
    int     count_char;

    count_char = 0;
    i = 0;
    va_start(ap, str);
    while (str[i] != '\0')
    {
        if (is_an_arg(str[i], str[i + 1]) != 0)
        {
            count_char += process_arg(str[i], str[i + 1], ap);
            i += 2;
        }
        else
        {
            count_char += write(1, &str[i++], 1);
        }
    }
    va_end(ap);
    return (count_char);
}
