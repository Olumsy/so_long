/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:21:45 by lspiteri          #+#    #+#             */
/*   Updated: 2025/06/18 20:40:46 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	ft_handle_cross(void *param)
{
	t_context	*context;

	context = (t_context *)param;
	ft_draw_game(*context, (t_point){0, 0}, 1);
	mlx_loop_end(context->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_map		map;
	void		*mlx;
	void		*win;
	t_context	context;

	if (argc != 2 || ft_check_map_name(argv[1], ".ber"))
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
	ft_draw_game(context, ft_sum_point(map.player_pos, (t_point){-2, -2}), 0);
	mlx_key_hook(win, ft_key_listener, &context);
	mlx_hook(win, 17, 0, ft_handle_cross, &context);
	mlx_loop(mlx);
	return (mlx_destroy_window(mlx, win), mlx_destroy_display(mlx), \
	free(mlx), ft_free_2d(&map.array), 0);
}
