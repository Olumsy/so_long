#include "./so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	map;
	
	int		fd;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	ft_map_init(&map);
	if (ft_read_map(&map, fd) || \
		ft_parsing(&map) || \
		ft_backtracking(&map))
		return (close(fd), ft_free_2d(&map.array), ft_werror("jack"), 1);
	//mlx here
	ft_gameloop(&map, &mlx);
	return (0);
}
