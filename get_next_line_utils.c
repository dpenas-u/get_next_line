/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenas-u <dpenas-u@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:30:42 by dpenas-u          #+#    #+#             */
/*   Updated: 2022/04/04 14:01:13 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

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
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (0);
		str[0] = 0;
		return (str);
	}
	if (len >= ft_strlen(s))
		str = malloc(sizeof(char) * (ft_strlen(s) + 1));
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

static	int	ft_countw(char const *s, char c);
static	void	ft_free(char **str, int i);
static	int	ft_aux(char **str, char const *s, char c, int n_splt);

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		n_splt;

	if (!s)
		return (0);
	if (!(*s))
	{
		str = malloc(sizeof(char *));
		if (!str)
			return (0);
		str[0] = 0;
		return (str);
	}
	n_splt = ft_countw(s, c);
	str = malloc(sizeof(char *) * (n_splt + 1));
	if (!str)
		return (0);
	if (!ft_aux(str, s, c, n_splt))
		return (0);
	return (str);
}

static	int	ft_aux(char **str, char const *s, char c, int n_splt)
{
	int	i;
	int	start;
	int	len;

	i = -1;
	start = -1;
	while (++i < n_splt)
	{
		while (*s && *s == c)
			s++;
		if (ft_strchr(s, c))
			len = ft_strchr(s, c) - s;
		else
			len = ft_strlen(s);
		str[i] = ft_substr(s, 0, len);
		if (!str[i])
		{
			ft_free(str, i);
			return (0);
		}
		s += len;
	}
	str[n_splt] = 0;
	return (1);
}

static	void	ft_free(char **str, int i)
{
	while (--i > -1)
		free(str[i]);
	free(str);
}

static	int	ft_countw(char const *s, char c)
{
	int	n;
	int	is_split;

	n = 0;
	is_split = 0;
	while (*s)
	{
		if (*s != c)
			is_split++;
		if (is_split && (*s == c || !*(s + 1)))
		{
			n++;
			is_split = 0;
		}
		s++;
	}
	return (n);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (dstsize <= ldst)
		return (dstsize + lsrc);
	i = -1;
	while (src[++i] && i < (dstsize - ldst - 1))
		ft_memset(dst + ldst + i, src[i], 1);
	dst[ldst + i] = 0;
	return (ldst + lsrc);
}

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		((unsigned char *)b)[len] = c;
	return (b);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		ls1;
	int		ls2;

	if (!s1 || !s2)
		return (0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!str)
		return (0);
	ft_memcpy(str, s1, ls1);
	ft_memcpy(str + ls1, s2, ls2);
	str[ls1 + ls2] = 0;
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (dst);
	while (n--)
		ft_memset(dst + n, ((unsigned char *)src)[n], 1);
	return (dst);
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(size * count);
	if (!mem)
		return (0);
	ft_bzero(mem, size * count);
	return (mem);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, &(*s++), 1);
}
