/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:03:50 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/26 11:33:26 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = (unsigned int)ft_strlen((char *)s);
	a = (unsigned char *)s;
	while (i < n)
	{
		if (*a == (unsigned char)c)
			return ((void *)a);
		a++;
		i++;
	}
	return (NULL);
}
