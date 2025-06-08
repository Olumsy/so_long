
typedef struct s_map	t_map;

typedef enum e_keys
{
    KEY_W     = 119,
    KEY_A     = 97,
    KEY_S     = 115,
    KEY_D     = 100,
    KEY_ESC   = 65307,
}   t_keys;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	**array;
	t_point	max;
	char	(*get_value)(t_map *, t_point);
	int		(*set_value)(t_map *, t_point, char);
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
	mlx		win;
}	t_context;
