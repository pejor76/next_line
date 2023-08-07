/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecampos <pecampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:52:37 by pecampos          #+#    #+#             */
/*   Updated: 2022/06/13 10:27:26 by pecampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	int		index;
	char	*dest;

	index = 0;
	dest = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!dest)
	{
		return (NULL);
	}
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *c)
{
	unsigned long	res;

	res = 0;
	while (c[res])
	{
		res++;
	}
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*str;
	int		x;
	int		y;

	if (!s1)
		return (ft_strdup((char *)s2));
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((size + 1) * sizeof(char));
	x = 0;
	while (s1[x] != 0)
	{
		str[x] = s1[x];
		x++;
	}
	y = 0;
	while (s2[y] != 0)
	{
		str[x] = s2[y];
		x++;
		y++;
	}
	str[size] = 0;
	return (str);
}

char	*ft_strchr(const char *string, int c)
{
	int	x;

	x = 0;
	while (string[x])
	{
		if (string[x] == (c % 256))
			return ((char *)(string + x));
		x++;
	}
	if (string[x] == (c % 256))
		return ((char *)(string + x));
	return (0);
}
