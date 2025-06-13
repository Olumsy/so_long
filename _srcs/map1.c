
#include "./so_long.h"

static char	get_value(t_map *map, t_point coord)
{
	if (coord.x > map->max.x -1 || coord.y > map->max.y -1 || \
		coord.x < 0 || coord.y < 0)
		return (-1);
	return (map->array[coord.y][coord.x]);
}

static int	set_value(t_map *map, t_point coord, char value)
{
	if (coord.x > map->max.x -1 || coord.y > map->max.y -1 || \
		coord.x < 0 || coord.y < 0)
		return (-1);
	map->array[coord.y][coord.x] = value;
	return (0);
}

void	ft_map_init(t_map *map)
{
	map->array = NULL;
	map->get_value = get_value;
	map->set_value = set_value;
	map->max = (t_point){0, 0};
	map->player_pos = (t_point){-1, -1};
	map->collectible_count = 0;
	map->under_player = '0';
}

t_point	ft_findchr_2d(t_map *map, char c)
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

char	**ft_strdup_2d(t_map *map)
{
	int		y;
	char	**dup;

	dup = malloc(sizeof(char *) * (map->max.y + 1));
	if (!dup)
		return (NULL);
	y = 0;
	while (y < map->max.y)
	{
		dup[y] = ft_strdup(map->array[y]);
		if (!dup[y])
			return (ft_free_2d(&dup), NULL);
		y++;
	}
	dup[y] = NULL;
	return (dup);
}
