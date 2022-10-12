/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedrole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:03:25 by mpedrole          #+#    #+#             */
/*   Updated: 2021/11/17 15:03:27 by mpedrole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

size_t	ft_strlenget(const char *str);

char	*ft_callocget(size_t size);

char	*ft_strsub(char const *s, unsigned int start, size_t len);

char	*ft_strdup(const char *s1);

char	*search_or_del(char **str, int c);

char	*get_next_line(int fd);
#endif
