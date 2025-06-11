
#include "./so_long.h"
#include <stdio.h>

static void	ft_sprites_init(void *mlx, void *sprites[6])
{
	int	w;
	int	h;
	
	(sprites[0]) = mlx_xpm_file_to_image(mlx, SPRITE_0, &w, &h);
	printf("mlx= %p\nimg= %p\n%s\n", mlx, sprites[0], SPRITE_0);
	(sprites[1]) = mlx_xpm_file_to_image(mlx, SPRITE_1, &w, &h);
	(sprites[2]) = mlx_xpm_file_to_image(mlx, SPRITE_E, &w, &h);
	(sprites[3]) = mlx_xpm_file_to_image(mlx, SPRITE_C, &w, &h);
	(sprites[4]) = mlx_xpm_file_to_image(mlx, SPRITE_P, &w, &h);
	(sprites[5]) = NULL;
}

int	ft_draw_game(t_context context, t_point start)
{
	void		*win;
	void		*mlx;
	static void	*sprites[6] = {NULL};
	int			i;
	char		c;

	win = context.win;
	mlx = context.mlx;
	if (!*sprites)
		ft_sprites_init(mlx, sprites);
	i = 0;
	return (1);
	while (i < 9)
	{
		c = context.map->get_value(context.map, \
		ft_sum_point((t_point) {i % 3, i / 3}, start));
		mlx_put_image_to_window(mlx, win, sprites[ft_findchr(SPRITE_ORDER, c)], \
		(i % 3) * SPRITE_SIZE, i / 3 * SPRITE_SIZE);
	}
	return (0);	
}
