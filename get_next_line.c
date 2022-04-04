/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenas-u <dpenas-u@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:07:24 by dpenas-u          #+#    #+#             */
/*   Updated: 2022/04/04 14:09:23 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include <stdio.h>

char	*get_next_line(int fd)
{
	static	char	*nxt_l;
	char	*b;
	char	*l;
	int	ret;
	char	*aux;
	char	*aux2;
	char	*aux3;
	char	*aux4;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (0);
	printf("\nnxt_l: %s\n", nxt_l);
	if (nxt_l)
		return (nxt_l);
	b = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!b)
		return (0);
	ret = read(fd, b, BUFFER_SIZE);
	b[ret] = 0;
	if (ret < 1)
	{
		free(b);
		return (0);
	}
	l = ft_strchr(b, 10);
	aux = 0;
	aux2 = 0;
	aux3 = 0;
	aux4 = 0;
	if (l)
	{
		aux = b;
		//free(b);
		if (!nxt_l)
			nxt_l = l + 1;
		else
		{
			aux2 = nxt_l;
			printf("\naux2: %s\n", aux2);
			nxt_l = ft_strjoin(aux2, l + 1);
		}
		printf("\naux: %s\n", aux);
		aux3 = ft_substr(aux, 0, l - aux + 1);
		printf("\naux3: %s\n", aux3);
		aux4 = aux3;
		printf("\nnxt_l: %s\n", nxt_l);
		free(aux3);
		printf("\nnxt_l: %s\n", nxt_l);
		return (aux4);
	}
	return (0);
}
