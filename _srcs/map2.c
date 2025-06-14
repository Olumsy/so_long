/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:19:40 by lspiteri          #+#    #+#             */
/*   Updated: 2025/06/14 19:19:42 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_countchar_2d(t_map *map, char c)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map->array[y])
	{
		x = 0;
		while (map->array[y][x])
			if (map->array[y][x++] == c)
				count++;
		y++;
	}
	return (count);
}
