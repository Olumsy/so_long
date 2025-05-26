
#include "./so_long.h"

static char	get_value(t_map *map, t_point coord)
{
	if (coord.x > map->max.x -1 || coord.y > map->max.y -1)
		return (-1);
	return (map->array[coord.y][coord.x]);
}

static int	set_value(t_map *map, t_point coord, char value)
{
	if (coord.x > map->max.x -1 || coord.y > map->max.y -1)
		return (-1);
	map->array[coord.y][coord.x] = value;
	return (0);
}

void	ft_map_init(t_map *map)
{
	map->array = NULL;
	map->max = (t_point){0, 0};
	map->it_legit = 0;
	map->get_value = get_value;
	map->set_value = set_value;
}

t_point ft_findchr_2d(t_map *map, char c)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->max.y)
	{
		x = ft_findchr(map->array[y], c);
		if (x >= 0)
			return ((t_point) {x, y});
		y++;
	}
	return ((t_point) {-1, -1});
}

/*
t_point ft_strdup_2d(t_map *map)
{
	;
}
*/
