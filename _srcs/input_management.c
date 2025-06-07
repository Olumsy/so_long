
#include "./so_long.h"

int	ft_player_movement(int	a);

t_point	ft_get_vector(int up, int down, int left, int right)
{
	return ((t_point) {down - up, right - left});
}
