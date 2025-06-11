
#include "./so_long.h"

static t_point	ft_get_vector(int up, int down, int left, int right)
{
	return ((t_point) {down - up, right - left});
}

static int	ft_player_movement(int	keycode, t_context *context)
{
	t_point	new_pos;
	t_map		*map;

	map = context->map;
	if (keycode)
	{
		map->set_value(map, map->player_pos, map->under_player);
		map->under_player = '0';
		new_pos = ft_sum_point(map->player_pos, ft_get_vector( \
			KEY_W == keycode, \
			KEY_S == keycode, \
			KEY_A == keycode, \
			KEY_D == keycode));
		if (map->get_value(map, new_pos) == '1')
			return (0);
		if (map->get_value(map, new_pos) == 'C')
			map->collectible_count--;
		if (map->get_value(map, new_pos) == 'E')
			map->under_player = 'E';
		map->player_pos = new_pos;
	}
	return (1);
}

int	ft_key_listener(int	keycode, t_context *context)
{
	static int	steps;

	if (ft_player_movement(keycode, context))
		steps++;
	if (keycode == KEY_ESC)
	{
		ft_putstr("esc\n");
	}
	return (0);
}
