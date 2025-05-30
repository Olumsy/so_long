
typedef struct s_map t_map;

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

typedef union
{
	struct
	{
		char	up;
		char	down;
		char	left;
		char	right;
	} s_dir;
	char	dirs[4];
}	u_cardinal;
