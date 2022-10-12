/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:08:38 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/25 14:15:17 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putchar_fd('-', fd);
		count += ft_putchar_fd('2', fd);
		count += ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		count += ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		count += ft_putnbr_fd(n / 10, fd);
		count += ft_putnbr_fd(n % 10, fd);
	}
	else
		return (ft_putchar_fd(n + '0', fd));
	return (count);
}
