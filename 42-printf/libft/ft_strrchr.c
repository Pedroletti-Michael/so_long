/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:34:24 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/26 11:56:22 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		z;
	int		len;
	char	*a;

	a = (char *) s;
	len = ft_strlen((char *)s);
	i = 0;
	z = -1;
	while (i <= len)
	{
		if (a[i] == (unsigned char)c)
			z = i;
		i++;
	}
	if (z < 0)
		return (0);
	else
		return (a + z);
}
