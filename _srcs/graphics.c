/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:14:19 by lspiteri          #+#    #+#             */
/*   Updated: 2025/06/14 19:15:37 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static void	ft_sprites_init(void *mlx, void *sprites[6])
{
	int	w;
	int	h;

	(sprites[0]) = mlx_xpm_file_to_image(mlx, SPRITE_0, &w, &h);
	(sprites[1]) = mlx_xpm_file_to_image(mlx, SPRITE_1, &w, &h);
	(sprites[2]) = mlx_xpm_file_to_image(mlx, SPRITE_E, &w, &h);
	(sprites[3]) = mlx_xpm_file_to_image(mlx, SPRITE_C, &w, &h);
	(sprites[4]) = mlx_xpm_file_to_image(mlx, SPRITE_P, &w, &h);
	(sprites[5]) = NULL;
}

int	ft_draw_game(t_context context, t_point start)
{
	static void	*sprites[6] = {NULL};
	int			sprite_index;
	int			i;
	char		c;

	if (!*sprites)
		ft_sprites_init(context.mlx, sprites);
	i = 0;
	while (i < 25)
	{
		c = context.map->get_value(context.map, \
		ft_sum_point((t_point){i % 5, i / 5}, start));
		sprite_index = ft_findchr(SPRITE_ORDER, c);
		if (sprite_index >= 0)
		{
			mlx_put_image_to_window(context.mlx, context.win, \
			sprites[sprite_index], \
			(i % 5) * SPRITE_SIZE, i / 5 * SPRITE_SIZE);
		}
		i++;
	}
	return (0);
}
