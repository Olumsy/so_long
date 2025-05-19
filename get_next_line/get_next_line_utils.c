/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:03 by lspiteri          #+#    #+#             */
/*   Updated: 2025/01/18 14:11:35 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

ssize_t	ft_strlen(const char *s)
{
	ssize_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

ssize_t	ft_findchr(const char *str0, int c0)
{
	ssize_t			i;
	char			*str;
	unsigned char	c;

	c = (unsigned char) c0;
	str = (char *)str0;
	i = 0;
	if (str0 == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

ssize_t	ft_strlcpy(char *dst0, const char *src0, ssize_t dstsize)
{
	ssize_t		i;
	char		*dst;
	const char	*src;

	i = 0;
	dst = dst0;
	src = src0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

void	ft_bzero(void *s, ssize_t n)
{
	ssize_t			i;
	unsigned char	*sbis;

	sbis = s;
	i = 0;
	while (i < n)
		sbis[i++] = '\0';
}
