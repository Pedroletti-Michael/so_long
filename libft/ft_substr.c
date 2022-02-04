/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:45:58 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/26 16:02:11 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*a;
	int				sz;

	if (!s)
		return (NULL);
	if ((len + start) > (unsigned int)ft_strlen(s))
		sz = (ft_strlen(s) - (ft_strlen(s) - start) + 1);
	else
		sz = len + 1;
	i = 0;
	if (start >= (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	a = (char *)malloc(sizeof(char) * sz);
	if (!a)
		return (NULL);
	while (i < len && s[start])
	a[i++] = (char) s[start++];
	a[i] = '\0';
	return (a);
}
