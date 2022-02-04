/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:28:30 by mpedrole          #+#    #+#             */
/*   Updated: 2021/10/25 15:04:47 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	nb_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
			&& (s[i] == c || s[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void	write_word(char *d, char const *s, char c)
{
	int	i;

	i = 0;
	while (!(s[i] == c || s[i] == '\0'))
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
}

static int	free_arr(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}

static int	fill_data(char **res, const char *s, char c)
{
	int	i;
	int	word;
	int	j;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c || s[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((s[i + j] == c || s[i + j] == '\0') == 0)
				j++;
			res[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!res[word])
				return (free_arr(res));
			write_word(res[word], s + i, c);
			i += j;
			word++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**res;

	if (!s)
		return (NULL);
	words = nb_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = NULL;
	if (!fill_data(res, s, c))
		return (NULL);
	return (res);
}
