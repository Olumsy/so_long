
#include "./so_long.h"

static t_point	ft_get_vector(int up, int down, int left, int right)
{
	return ((t_point) {right - left, down - up});
}

static int	ft_player_movement(int	key, t_context context)
{
	t_point	new_pos;
	_Bool		moved;
	t_map		*map;

	map = context.map;
	if (key)
	{
		new_pos = ft_sum_point(map->player_pos, ft_get_vector( \
		KEY_W == key, KEY_S == key, KEY_A == key, KEY_D == key));
		if (map->get_value(map, new_pos) == '1')
			return (0);
		map->set_value(map, map->player_pos, map->under_player);
		map->under_player = '0';
		if (map->get_value(map, new_pos) == 'C')
			map->collectible_count--;
		if (map->get_value(map, new_pos) == 'E')
			map->under_player = 'E';
		if (map->player_pos.x != new_pos.x || map->player_pos.y != new_pos.y)
			moved = 1;
		map->player_pos = new_pos;
		map->set_value(map, new_pos, 'P');
		mlx_clear_window(context.mlx, context.win);
		ft_draw_game(context, ft_sum_point(map->player_pos, (t_point){-2, -2}));
		return (moved);
	}
	return (0);
}

int	ft_key_listener(int	keycode, t_context *context)
{
	static int	steps;

	if (ft_player_movement(keycode, *context))
	{
		steps++;
		ft_putnbr_fd(steps, 1);
		ft_putstr("\n");
	}
	if (keycode == KEY_ESC || (context->map->under_player == 'E' && \
		 context->map->collectible_count == 0))
	{
		mlx_loop_end(context->mlx);
		return (0);
	}
	return (0);
}
