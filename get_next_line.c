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
	static	char	*nxt_line;
	//char	*aux;
	char	*buffer;
	char	*line;
	char	*not_line;
	//int		ret;
	//int		len;

	if (fd == -1)
		return (0);
	line = 0;
	not_line = 0;
	//printf("nxt_line: %s\n", nxt_line);
	ft_putstr_fd("UNO\n", 1);
	ft_putstr_fd(nxt_line, 1);
	ft_putstr_fd("\n", 1);
	//printf("VEZ\n");
	buffer = ft_calloc(1, (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	//ret = read(fd, buffer, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	ft_putstr_fd("Buffer\n", 1);
	ft_putstr_fd(buffer, 1);
	ft_putstr_fd("\n", 1);
//	printf("buf: %s\n", buffer);
	/*
	if (ret < 1)
	{
		free(buffer);
		return (0);
	}
	buffer[ret] = 0;
	*/
//	printf("nxt_line pre2: %s\n", nxt_line);
	ft_putstr_fd("Pre\n", 1);
	ft_putstr_fd(nxt_line, 1);
	ft_putstr_fd("\n", 1);
	if (!nxt_line)
	{
		ft_putstr_fd("\nENTRA AQUI\n", 1);
		nxt_line = ft_strdup(buffer);
	}
	//if (!nxt_line && ft_strlen(nxt_line) == 0)
	//{
	//	aux = ft_strdup(buffer);
		//nxt_line = ft_substr(buffer, 0, ft_strlen(buffer));
	//	nxt_line = aux;
	//}
	else
	{
		printf("AQUI\n");
		//printf("len nxt_line: %zu\n", ft_strlen(nxt_line));
		//printf("nxt_line 2: %s\n", nxt_line);
		nxt_line = ft_strjoin(nxt_line, ft_strdup(buffer));
	//	printf("len nxt_line: %zu\n", ft_strlen(nxt_line));
	}
	ft_putstr_fd("POST\n", 1);
	ft_putstr_fd(nxt_line, 1);
	ft_putstr_fd("\n", 1);
	//printf("nxt_line post: %s\n", nxt_line);

	line = nxt_line;

	
		/*
		//printf("buffer: %s\n", buffer);
		if (ft_strchr(buffer, 10))
		{
			not_line = ft_strchr(buffer, 10) + 1;
			printf("not_line: %s\n", not_line);
			len = ft_strchr(buffer, 10) - buffer;
			//printf("len: %i\n", len);
			line = ft_substr(buffer, 0, len + 1);
			//printf("line: %s", line);
			if (!nxt_line)
				nxt_line = not_line;
			else
				nxt_line = ft_strjoin(nxt_line, not_line);
			//printf("nxt_line: %s\n", nxt_line);
			free(buffer);
		}
		else
		{
			if (!nxt_line)
				nxt_line = buffer;
			else
				nxt_line = ft_strjoin(nxt_line, buffer);
			//printf("nxt_line: %s\n", nxt_line);
			free(buffer);
		}
		printf("nxt_line: %s\n", nxt_line);
	}
	*/
	/*
	printf("nxt_line: %s\n", nxt_line);
	if (nxt_line)
	{
		//printf("nxt_line: %s\n", nxt_line);
		if (ft_strchr(nxt_line, 10))
		{
			len = ft_strchr(nxt_line, 10) - nxt_line;
			line = ft_substr(nxt_line, 0, len + 1);
			nxt_line = ft_substr(nxt_line, len, ft_strlen(nxt_line));
		}
	}
	while (!line)
	{
		//printf("VEZ\n");
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 1)
		{
			free(buffer);
			return (0);
		}
		buffer[ret] = 0;
		//printf("buffer: %s\n", buffer);
		if (ft_strchr(buffer, 10))
		{
			not_line = ft_strchr(buffer, 10) + 1;
			//printf("not_line: %s\n", not_line);
			len = ft_strchr(buffer, 10) - buffer;
			//printf("len: %i\n", len);
			line = ft_substr(buffer, 0, len + 1);
			//printf("line: %s", line);
			if (!nxt_line)
				nxt_line = not_line;
			else
				ft_strlcat(nxt_line, not_line, ft_strlen(nxt_line) + ft_strlen(not_line) + 1);
			//printf("nxt_line: %s\n", nxt_line);
			free(buffer);
		}
		else
		{
			if (!nxt_line)
				nxt_line = buffer;
			else
				ft_strlcat(nxt_line, buffer, ft_strlen(nxt_line) + ft_strlen(buffer) + 1);
			//printf("nxt_line: %s\n", nxt_line);
			free(buffer);
		}
		//printf("nxt_line: %s\n", nxt_line);
	}
	*/
	free(buffer);
	return (line);
}
