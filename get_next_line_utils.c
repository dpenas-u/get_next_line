/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenas-u <dpenas-u@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:30:42 by dpenas-u          #+#    #+#             */
/*   Updated: 2022/04/05 15:11:07 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (start >= i)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (0);
		str[0] = 0;
		return (str);
	}
	if (len >= i)
		str = malloc(sizeof(char) * (i + 1));
	else
		str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = -1;
	while (++i < len && s[start + i])
		str[i] = s[start + i];
	str[i] = 0;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		ls1;
	int		ls2;
	int		i;

	if (!s1 || !s2)
		return (0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!str)
		return (0);
	i = -1;
	while (++i < ls1)
		str[i] = s1[i];
	i = -1;
	while (++i < ls2)
		str[i + ls1] = s2[i];
	str[ls1 + ls2] = 0;
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (0);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = 0;
	return (s2);
}
