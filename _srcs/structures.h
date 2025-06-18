/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:26:27 by lspiteri          #+#    #+#             */
/*   Updated: 2025/06/18 20:17:21 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_map	t_map;

typedef enum e_keys
{
	KEY_UP	= 119,
	KEY_LEFT	= 97,
	KEY_DOWN	= 115,
	KEY_RIGHT	= 100,
	KEY_ESC	= 65307,
}	t_keys;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	**array;
	char	(*get_value)(t_map *, t_point);
	int		(*set_value)(t_map *, t_point, char);
	t_point	max;
	t_point	player_pos;
	char	under_player;
	int		collectible_count;
}	t_map;

typedef union u_cardinal
{
	struct
	{
		char	up;
		char	down;
		char	left;
		char	right;
	} s_dir;
	char	dirs[4];
}	t_cardinal;

typedef struct s_context
{
	t_map	*map;
	void	*mlx;
	void	*win;
}	t_context;
