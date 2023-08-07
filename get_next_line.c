/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecampos <pecampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:52:37 by pecampos          #+#    #+#             */
/*   Updated: 2023/03/16 18:52:56 by pecampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buf)
{
	char	*res;
	int		size;
	char	*c;

	res = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!res)
		return (NULL);
	size = 1;
	while (size != 0)
	{
		size = read(fd, res, BUFFER_SIZE);
		if (buf == NULL && size <= 0)
		{
			free(res);
			return (NULL);
		}
		res[size] = '\0';
		c = buf;
		buf = ft_strjoin(buf, res);
		free(c);
		if (ft_strchr(buf, '\n') != NULL)
			size = 0;
	}
	free(res);
	return (buf);
}

char	*ft_line(char *buf)
{
	int		i;
	char	*res;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	res = (char *)malloc((i + 2) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		res[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_keep(char *buf)
{
	unsigned long	x;
	char			*s;

	if (!*buf)
		return (NULL);
	x = 0;
	while (buf[x] != '\n' && buf[x])
		x++;
	if (buf[x] == '\n' && buf[x + 1] != '\0')
	{
		s = buf;
		buf = ft_strdup(&buf[x + 1]);
		free (s);
	}
	else
	{
		free (buf);
		buf = NULL;
		return (buf);
	}
	buf[ft_strlen(buf)] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read(fd, buf);
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
	res = ft_line(buf);
	if (!res)
	{
		free(buf);
		return (NULL);
	}
	buf = ft_keep(buf);
	if (buf == NULL && res == NULL)
		return (NULL);
	return (res);
}

void	showleaks(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	int		fd;
	int		i;
	char	*c;

	i = 0;
	fd = open("test.ber", O_RDONLY);
	c = get_next_line(fd);
	/* while (c != NULL)
	{
		printf(">%s<\n", c);
		free(c);
		i++;
		c = get_next_line(fd);
	} */
	close(fd);
	showleaks();
	return (0);
}
