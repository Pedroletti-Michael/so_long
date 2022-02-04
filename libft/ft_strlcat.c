/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:56:11 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/25 14:16:54 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	ld;
	unsigned int	ls;
	unsigned int	k;

	ld = ft_strlen(dest);
	ls = ft_strlen((char *)src);
	k = 0;
	if (size <= ld)
		ls += size;
	else
		ls += ld;
	while (src[k] != '\0' && ld + 1 < size)
	{
		dest[ld] = src[k];
		ld++;
		k++;
	}
	dest[ld] = '\0';
	return (ls);
}
