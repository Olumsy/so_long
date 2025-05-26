
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

int	ft_read_map(t_map *map, int fd)
{
	int	len;
	int	y;

	map->array = ft_split(ft_get_file(fd), '\n');
	y = 0;
	len = ft_strlen(map->array[y]);
	while (map->array[y])
	{
		if ((int) ft_strlen(map->array[y++]) != len)
			return (-1);
	}
	map->max = (t_point) {len, y};
	return (0);
}

static t_point	ft_advance(t_point *map, t_point *pos)
{
	t_point	nhbr;
	int		x[4];
	int		y[4];
	int		i;

	x = {0, 0, -1, 1};
	y = {1, -1, 0, 0};
	i = 0;
	while (i < 4)
	{
		nhbr = {pos->x + x[i], pos->y + y[i]};
		if (map->get_value(nhbr) != 1 && \
			 map->get_value(nhbr) != -1)
			return (*pos = nhbr, 0);
		i++;
	}
	return (1);
}

static int	ft_backtracking(t_map *map)
{
	;	
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	int	fd;
	int	x;
	int	y;
	t_map	map;

	(void) argc;
	ft_map_init(&map);
	fd = open(argv[1], O_RDONLY);
	ft_read_map(&map, fd);
	int	i = 0;
	while (map.array[i])
	{
		printf("%s\n", map.array[i++]);
	}
	y = 0;
	while (scanf("%d%d", &x, &y))
	{
		printf("> %c\n", map.get_value(&map, ft_advance(&map, t_point){x, y}));
	}
	return (0);
}
