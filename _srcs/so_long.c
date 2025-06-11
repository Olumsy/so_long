#include "./so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	void	*mlx;
	void	*win;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_werror("ERROR > Invalid map path\n"), 1);
	ft_map_init(&map);
	if (ft_read_map(&map, fd) || \
		ft_parsing(&map) || \
		ft_backtracking(&map))
		return (close(fd), ft_free_2d(&map.array), ft_werror("jack"), 1);
	//mlx here
	mlx = mlx_init();
	win = mlx_new_window(mlx, SPRITE_SIZE * 3, SPRITE_SIZE * 3, "So_long");
	ft_draw_game((t_context){&map, &mlx, &win}, (t_point){0, 0});
	while (1)
		;
	//ft_gameloop(&map, &mlx);
	return (0);
}
