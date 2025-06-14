/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:21:15 by lspiteri          #+#    #+#             */
/*   Updated: 2025/06/14 19:31:01 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static char	*ft_get_file(int fd)
{
	int		readbyte;
	int		total_len;
	char	buff[BUFFER_SIZE];
	char	*str;

	str = NULL;
	total_len = 0;
	readbyte = 1;
	while (readbyte)
	{
		readbyte = read(fd, buff, BUFFER_SIZE);
		total_len += readbyte;
		str = ft_realloc(str, total_len + 1);
		ft_strlcat(str, buff, total_len + 1);
		ft_bzero(buff, BUFFER_SIZE);
	}
	return (str);
}

static int	ft_check_emptyline(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (c == str[i] || i == 0))
			return (1);
		c = str[i];
		i++;
	}
	return (0);
}

int	ft_read_map(t_map *map, int fd)
{
	int		len;
	int		y;
	char	*temp;

	temp = ft_get_file(fd);
	map->array = ft_split(temp, '\n');
	if (ft_strlen(temp) == 0)
		return (free(temp), ft_werror(" ERROR: Empty map.\n"), 1);
	if (ft_check_emptyline(temp))
		return (free(temp), ft_werror(" ERROR: Empty line in map.\n"), 1);
	free(temp);
	y = 0;
	len = ft_strlen(map->array[y]);
	while (map->array[y])
	{
		if ((int) ft_strlen(map->array[y++]) != len)
			return (ft_werror(" ERROR: Map must be a rectangle.\n"), 1);
	}
	map->max = (t_point){len, y};
	map->player_pos = ft_findchr_2d(map, 'P');
	map->collectible_count = ft_countchar_2d(map, 'C');
	return (0);
}
