#include "./so_long.h"

static int	ft_check_map_name(char *str, char *ext)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == ext[j])
		{
			j++;
			if (!ext[j])
				return (0);
		}
		i++;
	}
	return (ft_werror(" ERROR: Map must be \"[map_name].ber\".\n"), 1);
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
	if (ft_check_map_name(argv[1], ".ber"))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_werror(" ERROR: Invalid map path.\n"), 1);
	ft_map_init(&map);
	if (ft_read_map(&map, fd) || \
		ft_parsing(&map) || \
		ft_backtracking(&map))
		return (close(fd), ft_free_2d(&map.array), 1);
	mlx = mlx_init();
	win = mlx_new_window(mlx, SPRITE_SIZE * 5, SPRITE_SIZE * 5, "So_long");
	context = (t_context){&map, mlx, win};
	ft_draw_game(context, ft_sum_point(map.player_pos, (t_point){-2, -2}));

	mlx_key_hook(win, ft_key_listener, &context);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
    mlx_destroy_display(mlx);
    free(mlx);
	return (ft_free_2d(&map.array), 0);
}
