/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:25:50 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/25 14:16:18 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		len;

	len = ft_strlen(src);
	ptr = (char *) malloc (len + 1);
	if (ptr != NULL)
		ft_strlcpy(ptr, src, len + 1);
	else
		return (NULL);
	return (ptr);
}
