
#include "./so_long.h"

int	get_value(t_map *map, t_point coord)
{
	if (coord.x > map.max.x || coord.y > map.max.y)
		return (-1);
	return (arr[coord.y][coord.x]);
}

int	set_value(t_map *map, t_point coord, unsigned char value)
{
	if (coord.x > map.max.x || coord.y > map.max.y)
		return (-1);
	arr[coord.x + coord.y * (map.max.x + 2)] = value;
	return (0);
}

int	ft_map_init(t_map *map)
{
	map.map = NULL;
	map.max = (t_point){0, 0};
	map.it_legit = 0;
	map.get_value = get_value;
	map.set_value = set_value;
}
