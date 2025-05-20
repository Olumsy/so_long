
#include "./so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (1);
	ft_map_init(&map);
    ft_read_map(&map, open(argv[2], O_RDONLY));
	
	return (0);
}
