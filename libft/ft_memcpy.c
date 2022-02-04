/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:29:04 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/25 14:14:16 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int				i;
	char			*d;
	const char		*s;

	d = (char *)dest;
	s = (const char *)src;
	i = (int)n;
	if (d == NULL && s == NULL)
		return (NULL);
	while (i > 0)
	{
		*d++ = *s++;
		i--;
	}
	return (dest);
}
