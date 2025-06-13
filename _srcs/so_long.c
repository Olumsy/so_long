#include "./so_long.h"
#include <stdio.h>

int	key_hook(int keycode, t_context *context)
{
	printf("key = %d\n", keycode);
	ft_key_listener(keycode, context);
	int	i = 0;
	while (context->map->array[i])
	{
		printf("%s\n", context->map->array[i++]);
	}
	printf("\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	t_context	context;
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
	mlx = mlx_init();
	win = mlx_new_window(mlx, SPRITE_SIZE * 5, SPRITE_SIZE * 5, "So_long");
	context = (t_context){&map, mlx, win};
	ft_draw_game(context, ft_sum_point(map.player_pos, (t_point){-2, -2}));

	mlx_key_hook(win, key_hook, &context);
	//mlx_key_hook(win, ft_key_listener, &context);
	mlx_loop(mlx);
	//ft_gameloop(&map, &mlx);
	return (0);
}
