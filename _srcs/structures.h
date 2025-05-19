
typedef struct s_map t_map;

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}	t_point;

typedef struct s_map
{
	unsigned char	*array;
	t_point			max;
	_Bool			it_legit;	
	int				(*get_value)(t_map *, t_point);
	int				(*set_value)(t_map *, t_point, unsigned char);
}	t_map;
