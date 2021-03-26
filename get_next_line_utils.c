/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoon <mmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:58:29 by mmoon             #+#    #+#             */
/*   Updated: 2021/03/03 17:04:40 by mmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == ((char)c))
			return ((char *)s);
		if (!*s++)
			break ;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	const char	*src0;
	char		dummy[1];

	src0 = src;
	if (!n)
		dst = dummy;
	else
		--n;
	while (*src)
	{
		*dst = *src;
		if (n)
		{
			--n;
			++dst;
		}
		++src;
	}
	*dst = *src;
	return (src - src0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	len;
	char	dummy[1];

	len = 0;
	while (1)
	{
		if (len >= n)
		{
			dst = dummy;
			break ;
		}
		if (!*dst)
			break ;
		++dst;
		++len;
	}
	while (*src)
	{
		*dst = *src;
		if (++len < n)
			++dst;
		++src;
	}
	*dst = *src;
	return (len);
}

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*r1;
	const char	*r2;

	if (!s1 && !s2)
		return (0);
	r1 = s1;
	r2 = s2;
	while (n)
	{
		*r1++ = *r2++;
		--n;
	}
	return (s1);
}
