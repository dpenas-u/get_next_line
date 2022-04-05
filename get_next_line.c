/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenas-u <dpenas-u@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:07:24 by dpenas-u          #+#    #+#             */
/*   Updated: 2022/04/05 12:22:15 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_read_buff(int fd, char **nxt_l);
static char	*ft_get_line(char **nxt_l, int ret);

char	*get_next_line(int fd)
{
	static char	*nxt_l;
	int			ret;
	char		*line;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (0);
	line = 0;
	ret = -2;
	while (!line)
	{
		if (nxt_l)
		{
			line = ft_get_line(&nxt_l, ret);
			if (line)
				break ;
		}
		ret = ft_read_buff(fd, &nxt_l);
		if (ret == -1)
			return (0);
		if (!ft_strlen(nxt_l))
			return (0);
	}
	return (line);
}

static char	*ft_get_line(char **nxt_l, int ret)
{
	char	*l;
	char	*aux;
	char	*line;

	line = 0;
	l = ft_strchr(*nxt_l, 10);
	if (l)
	{
		line = ft_substr(*nxt_l, 0, l - *nxt_l + 1);
		aux = ft_substr(l + 1, 0, ft_strlen(l + 1));
		free(*nxt_l);
		*nxt_l = aux;
	}
	if (!ret)
	{
		line = ft_substr(*nxt_l, 0, ft_strlen(*nxt_l));
		if (*nxt_l)
			free(*nxt_l);
		*nxt_l = 0;
	}
	return (line);
}

static int	ft_read_buff(int fd, char **nxt_l)
{
	char	*b;
	char	*aux;
	int		ret;

	b = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!b)
		return (-1);
	ret = read(fd, b, BUFFER_SIZE);
	b[ret] = 0;
	if (ret < 0)
	{
		free(b);
		return (-1);
	}
	if (*nxt_l && ft_strlen(*nxt_l))
		aux = ft_strjoin(*nxt_l, b);
	else
		aux = ft_strdup(b);
	free(*nxt_l);
	*nxt_l = aux;
	free(b);
	return (ret);
}
