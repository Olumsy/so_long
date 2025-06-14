/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:19:57 by lspiteri          #+#    #+#             */
/*   Updated: 2025/06/14 19:20:30 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static int	ft_check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (map->array[0][i])
		if (map->array[0][i++] != '1')
			return (1);
	i = 0;
	while (map->array[0][i])
		if (map->array[map->max.y - 1][i++] != '1')
			return (1);
	i = 0;
	while (i < map->max.y - 1)
	{
		if (map->array[i][0] != '1' || map->array[i][map->max.x - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_in_whitelist(t_map *map, char *wlist)
{
	int	x;
	int	y;
	int	i;
	int	len;

	y = 0;
	len = ft_strlen(wlist);
	while (y < map->max.y)
	{
		x = 0;
		while (x < map->max.x)
		{
			i = 0;
			while (1)
			{
				if (i == len)
					return (1);
				if (map->get_value(map, (t_point){x, y}) == wlist[i++])
					break ;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_parsing(t_map *map)
{
	if (ft_check_walls(map))
		return (ft_werror(" ERROR: Map must be surrounded by walls.\n"), 1);
	if (ft_countchar_2d(map, 'P') != 1)
		return (ft_werror(" ERROR: Map must have 1 player.\n"), 1);
	if (ft_countchar_2d(map, 'C') < 1)
		return (ft_werror(" ERROR: Map must have 1+ collectible(s).\n"), 1);
	if (ft_check_in_whitelist(map, "01PEC"))
		return (ft_werror(" ERROR: Map charset is \"01PEC\".\n"), 1);
	if (ft_countchar_2d(map, 'E') != 1)
		return (ft_werror(" ERROR: Map must have 1 exit.\n"), 1);
	return (0);
}
