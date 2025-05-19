
#include "./so_long.h"

int	main(int argc, char **argv)
{
	

	int	fd;

	if (argc != 2)
		return (1);
    fd = open(argv[1], O_RDONLY);

	return (0);
}
