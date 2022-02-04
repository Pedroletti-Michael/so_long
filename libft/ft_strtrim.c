/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:42:45 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/25 14:18:42 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	chck_occ(char s, char const *set)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s)
			res = 1;
		i++;
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*res;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup((char *)s1));
	start = 0;
	while (s1[start] && chck_occ(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && chck_occ(s1[end - 1], set))
		end--;
	res = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!res)
		return (0);
	i = 0;
	while (start < end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
