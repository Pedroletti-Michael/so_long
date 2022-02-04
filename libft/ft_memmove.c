/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:36:50 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/25 14:14:29 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	int			i;
	const char	*s;
	char		*d;
	char		*ls;
	char		*ld;

	i = 0;
	s = (const char *)src;
	d = (char *)dest;
	ls = (char *)src + (len - 1);
	ld = (char *)dest + (len - 1);
	if (d == NULL && s == NULL)
		return (NULL);
	if (d < s)
	{
		while (len--)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		while (len--)
			*ld-- = *ls--;
	return (dest);
}
