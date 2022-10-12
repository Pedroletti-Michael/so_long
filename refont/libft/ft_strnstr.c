/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:21:15 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/25 14:18:10 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	test_needle(char *haystack, char *needle, unsigned int n, unsigned int i)
{
	unsigned int		j;

	j = 0;
	while (needle[j] != '\0' && (i + j) <= n)
	{
		if (needle[j] != haystack[j])
			return (1);
		j++;
	}
	if (i + j > n)
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int		i;
	char				*a;
	char				*b;

	a = (char *)haystack;
	b = (char *)needle;
	i = 0;
	if (!*needle)
		return (a);
	while (i < n && *a != '\0')
	{
		if (*a == b[0])
		{
			if (test_needle(a, b, n, i) == 0)
				return (a);
		}
		a++;
		i++;
	}
	return (0);
}
