/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:12:44 by lspiteri          #+#    #+#             */
/*   Updated: 2025/06/14 19:13:34 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static t_point	ft_advance(t_map *map, t_point *pos)
{
	t_point		nhbr;
	t_cardinal	x;
	t_cardinal	y;
	int			i;

	x.s_dir = (typeof(x.s_dir)){0, 0, -1, 1};
	y.s_dir = (typeof(y.s_dir)){-1, 1, 0, 0};
	i = 0;
	while (i < 4)
	{
		nhbr = (t_point){pos->x + x.dirs[i], \
							pos->y + y.dirs[i]};
		if (map->get_value(map, nhbr) != '1' && \
			map->get_value(map, nhbr) != -1)
			return (nhbr);
		i++;
	}
	return ((t_point){-1, -1});
}

static int	ft_flood(t_map *map, t_point current)
{
	t_point	next;
	int		count;

	count = 0;
	map->set_value(map, current, '1');
	while (count < 4)
	{
		count++;
		next = ft_advance(map, &current);
		if (next.x != -1)
			ft_flood(map, next);
	}
	return (0);
}

int	ft_backtracking(t_map *src)
{
	t_map	map;
	int		rvalue;

	ft_map_init(&map);
	map.array = ft_strdup_2d(src);
	map.max = (t_point){src->max.x, src->max.y};
	ft_flood(&map, ft_findchr_2d(&map, 'P'));
	rvalue = (ft_findchr_2d(&map, 'C').x >= 0 || \
		ft_findchr_2d(&map, 'E').x >= 0);
	return (ft_free_2d(&(map.array)), rvalue && \
	ft_werror(" ERROR: Map impossible.\n"), rvalue);
}
