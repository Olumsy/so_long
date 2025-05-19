/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:23:46 by lspiteri          #+#    #+#             */
/*   Updated: 2025/01/16 19:55:01 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_makeline(char **s1, const char *s2, int s2_len)
{
	int		i;
	int		j;
	int		s1_len;
	char	*str;

	i = 0;
	s1_len = ft_strlen(*s1);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (i < s1_len)
	{
		str[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && j < s2_len && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (ft_free(s1), str);
}

static char	*return_line(char *line, char (*save)[BUFFER_SIZE], int size)
{
	ft_bzero(*save, BUFFER_SIZE);
	ft_strlcpy(*save, line + size + 1, ft_strlen(line) - size);
	line[size + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*line;
	static char	save[BUFFER_SIZE];
	int			readbytes;
	int			nlindex;

	line = NULL;
	readbytes = fd >= 0;
	if (save[0])
		line = ft_makeline(&line, save, ft_strlen(save));
	while (readbytes > 0)
	{
		nlindex = ft_findchr(line, '\n');
		if (nlindex >= 0)
			return (return_line(line, &save, nlindex));
		ft_bzero(buffer, BUFFER_SIZE);
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
			return (ft_free(&line), save[0] = '\0', NULL);
		if (readbytes)
			line = ft_makeline(&line, buffer, BUFFER_SIZE);
	}
	if (readbytes == 0 && line)
		return (return_line(line, &save, ft_strlen(line) - 1));
	return (ft_free(&line), NULL);
}
