/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:07:50 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/26 14:29:02 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *a, char const *b)
{
	char	*r;
	int		i;

	if (!a)
		return (NULL);
	i = ft_strlen(a);
	if (ft_strncmp(a, "", ft_strlen(a)) == 0
		&& ft_strncmp(b, "", ft_strlen(b)) == 0)
		return (ft_strdup(""));
	if (a && b)
	{
		r = (char *) malloc((ft_strlen((char *)a) + ft_strlen((char *)b) - 1));
		if (r == NULL)
			return (NULL);
		ft_strlcpy(r, a, ++i);
		i--;
		ft_strlcpy(r + i, b, ft_strlen(b) + 1);
		return (r);
	}
	else
		return (NULL);
}
