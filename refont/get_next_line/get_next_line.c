/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:03:11 by mpedrole          #+#    #+#             */
/*   Updated: 2021/11/17 15:03:12 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = src[i];
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		strlen;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	strlen = ft_strlenget(s1) + ft_strlenget(s2);
	str = ft_callocget(strlen);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy(str + ft_strlenget(s1), s2);
	return (str);
}

static char	*get_line(char **s)
{
	int		len;
	char	*tmp;
	char	*line;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		line = ft_strsub(*s, 0, len + 1);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			search_or_del(s, -1);
	}
	else
	{
		line = ft_strdup(*s);
		search_or_del(s, -1);
	}
	return (line);
}

static char	*format_output(char **s, int ret)
{
	if (ret < 0)
		return (NULL);
	else if (ret == 0 && *s == NULL)
		return (NULL);
	else
		return (get_line(s));
}

char	*get_next_line(int fd)
{
	int			ret;
	static char	*s;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0)
		return (NULL);
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (s == NULL)
			s = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s, buff);
			free(s);
			s = tmp;
		}
		if (search_or_del(&s, '\n'))
			break ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	return (format_output(&s, ret));
}
