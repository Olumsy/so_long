
#include "./so_long.h"

static char	get_value(t_map *map, t_point coord)
{
	if (coord.x > map->max.x || coord.y > map->max.y)
		return (-1);
	return (map->array[coord.y][coord.x]);
}

static int	set_value(t_map *map, t_point coord, char value)
{
	if (coord.x > map->max.x || coord.y > map->max.y)
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
