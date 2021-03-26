/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoon <mmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:58:29 by mmoon             #+#    #+#             */
/*   Updated: 2021/03/03 17:04:40 by mmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(len);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len);
	free(s1);
	ft_strlcat(str, s2, len);
	return (str);
}

char	*ft_strdup(const char *s1, int l)
{
	char	*s;

	s = malloc(l + 1);
	if (!s)
		return (0);
	ft_memcpy(s, s1, l);
	s[l] = 0;
	return (s);
}

int		ret(char **line, char **next, char *temp)
{
	char	*tmp;

	if (temp)
	{
		*line = ft_strdup(*next, temp - *next);
		++temp;
		tmp = ft_strdup(temp, ft_strlen(temp));
		free(*next);
		*next = tmp;
		return (1);
	}
	if (*next)
	{
		*line = *next;
		*next = 0;
	}
	else
		*line = ft_strdup("", 1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*next[OPEN_MAX];
	char		*temp;
	int			size;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (!(temp = ft_strchr(next[fd], '\n'))
	&& (size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = 0;
		next[fd] = ft_strjoin(next[fd], buf);
	}
	if (size < 0)
		return (-1);
	return (ret(line, &next[fd], temp));
}
