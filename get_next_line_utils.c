/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nlecaill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 19:59:57 by nlecaill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 18:01:13 by nlecaill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*new;
	int		size;
	int		nb_cpy;

	if (s2 == NULL)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = malloc(sizeof(char) * (size + 1))))
	{
		free(s1);
		return (0);
	}
	nb_cpy = ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcpy((new + nb_cpy), s2, ft_strlen(s2) + 1);
	free(s1);
	return (new);
}

size_t	ft_strlen(const char *s)
{
	unsigned long i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int src_lenght;

	i = 0;
	src_lenght = 0;
	if (dst == NULL || src == NULL)
		return (0);
	while (src[src_lenght] != '\0')
		src_lenght++;
	if (size == 0)
		return (src_lenght);
	while (size-- > 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_lenght);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;

	i = 0;
	if (dst == NULL || src == NULL)
		return (dst);
	if (dst > src)
	{
		while (len--)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	if (src > dst)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

int		ft_strchr(const char *s, int c)
{
	char	d;
	int		i;

	i = 0;
	d = c;
	if (d == '\0')
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return (i);
		i++;
	}
	return (-1);
}
