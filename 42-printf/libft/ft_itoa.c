/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:42:52 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/25 14:13:35 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	int_len(int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

static char	*trans_char(int n, int neg, char *res, int len)
{
	int	i;

	i = 0;
	if (neg > 0)
		res[i++] = '-';
	if (neg == 2)
	{
		res[i++] = '2';
		n = 147483648;
	}
	res[len--] = '\0';
	while (len >= i)
	{
		res[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		neg;

	len = 0;
	neg = 0;
	if (n == -2147483648)
	{
		len = 11;
		neg = 2;
	}
	else if (n < 0)
	{
		len++;
		n *= -1;
		neg = 1;
	}
	if (neg < 2)
		len += int_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res = trans_char(n, neg, res, (len));
	return (res);
}
