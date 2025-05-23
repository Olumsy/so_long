
#include "./so_long.h"

static char	*ft_get_file(int fd)
{
	int		readbyte;
	int		total_len;
	char	buff[BUFFER_SIZE];
	char	*str;

	total_len = 0;
	readbyte = 1;
	while (readbyte)
	{
		readbyte = read(fd, buff, BUFFER_SIZE);
		total_len += readbyte;
		str = ft_realloc(str, total_len + 1);
		ft_strlcat(str, buff, total_len + 1);
		ft_bzero(buff, BUFFER_SIZE);
	}
	return (str);
}

int	ft_read_map(t_map *map, int fd)
{
	int		len;
	int		total_len;
	char	*temp;

	temp = get_next_line(fd);
	len = ft_strlen(temp);
	total_len = len;
	while (temp)
	{
		if ((int) ft_strlen(temp) != len)
			return (free(temp), 1);
		ft_realloc(map->array, total_len + 1);
		ft_strlcat(map->array, temp, ft_strlen(map->array));
		free(temp);
		temp = NULL;
		temp = get_next_line(fd);
		total_len += len;
	}
	return (0);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	printf("%s\n", ft_get_file(fd));
	return (0);
}
