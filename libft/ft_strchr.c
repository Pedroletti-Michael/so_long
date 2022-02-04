/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:28:27 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/26 11:55:27 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*a;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)str);
	a = (char *) str;
	while (i <= len)
	{
		if (*a == (unsigned char)c)
			return ((void *)a);
		a++;
		i++;
	}
	return (0);
}
