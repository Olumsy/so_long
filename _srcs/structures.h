
typedef struct s_map t_map;

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}	t_point;

typedef struct s_map
{
	char	*array;
	t_point	max;
	_Bool	it_legit;	
	int		(*get_value)(t_map *, t_point);
	int		(*set_value)(t_map *, t_point, char);
}	t_map;
