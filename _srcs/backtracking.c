
#include "./so_long.h"
#include <stdio.h>

static int	ft_advance(t_map *map, t_point *pos)
{
	t_point		nhbr;
	u_cardinal	x;
	u_cardinal	y;
	int			i;

	x.s_dir = (typeof(x.s_dir)) {0, 0, -1, 1};
	y.s_dir = (typeof(y.s_dir)) {1, -1, 0, 0};
	i = 0;
	while (i < 4)
	{
		nhbr = (t_point) {pos->x + x.dirs[i], pos->y + y.dirs[i]};
		if (map->get_value(map, nhbr) != '1' && \
			 map->get_value(map, nhbr) != -1)
			return (*pos = nhbr, 0);
		i++;
	}
	return (1);
}

static int	ft_flood(t_map *map, t_point current)
{
	map->set_value(map, current, '1');
	int	i = 0;
	printf("------------\n  ABCDEFGHIJKL\n\n");
	usleep(30000);
	while (map->array[i])
	{
		printf("%d %s\n", i, map->array[i]);
		i++;
	}
	while (!ft_advance(map, &current))
		ft_flood(map, current);
	return (0);
}

int	ft_backtracking(t_map *map)
{
	ft_flood(map, ft_findchr_2d(map, 'P'));
	return ((ft_findchr_2d(map, 'C').x >= 0 || \
		ft_findchr_2d(map, 'P').x >= 0|| \
		ft_findchr_2d(map, 'E').x >= 0));
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	int	fd;
	t_map	map;
	t_point	current;

	(void) argc;
	ft_map_init(&map);
	fd = open(argv[1], O_RDONLY);
	ft_read_map(&map, fd);
	int	i = 0;
	while (map.array[i])
	{
		printf("%s\n", map.array[i++]);
	}
	printf("> max value: {%d, %d}\n", map.max.x, map.max.y);
	printf("> invalid ? %d\n", ft_backtracking(&map));

	while (scanf("%d%d", &current.x, &current.y))
	{
		printf("> {%d, %d} %c\n", current.x, current.y, map.get_value(&map, current));
		ft_advance(&map, &current);
		printf("> next is {%d, %d} %c\n", current.x, current.y, map.get_value(&map, current));
	}

	return (0);
}
