#include <stdio.h>
int	main(int argc, char **argv)
{
	int	i = 0;

	while (i < 9)
	{
		printf("{%d, %d}\n", i % 3, i / 3);
		i++;
	}
	return (0);
}
