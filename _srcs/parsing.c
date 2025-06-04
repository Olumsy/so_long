
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
				if (map->get_value(map, (t_point) {x, y}) == wlist[i++])
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
	return (ft_check_walls(map) || \
	ft_countchar_2d(map, 'P') != 1 || \
	ft_countchar_2d(map, 'C') < 1 || \
	ft_check_in_whitelist(map, "01PEC") || \
	ft_countchar_2d(map, 'E') != 1);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	fd;
	t_map	map;
	t_point	current;

	(void) argc;
	ft_map_init(&map);
	fd = open(argv[1], O_RDONLY);
	
	printf("> reading ? %d\n", ft_read_map(&map, fd));
	int	i = 0;
	while (map.array[i])
	{
		printf("%s\n", map.array[i++]);
	}
	printf("> max value: {%d, %d}\n", map.max.x, map.max.y);
	printf("> parsing ? %d\n", ft_parsing(&map));
	printf("> backtracking ? %d\n", ft_backtracking(&map));

	while (scanf("%d%d", &current.x, &current.y))
	{
		printf("> {%d, %d} %c\n", current.x, current.y, map.get_value(&map, current));
	}

	return (0);
}
*/
