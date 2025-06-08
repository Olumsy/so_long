
#include "./so_long.h"

int	ft_player_movement(int	a);

static t_point	ft_get_vector(int up, int down, int left, int right)
{
	return ((t_point) {down - up, right - left});
}

int	ft_key_listener(int	keycode, t_context context)
{
	t_map	*map;
	void	*win;

	map = context->map;
	win = context->win;
	if (keycode == KEY_ESC)
		ft_putstr("esc\n");
	return (0);
}
