
#include "./so_long.h"

static char	*ft_get_file(int fd)
{
	int		readbyte;
	int		total_len;
	char	buff[BUFFER_SIZE];
	char	*str;

	str = NULL;
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
	int	len;
	int	y;

	map->array = ft_split(ft_get_file(fd), '\n');
	y = 0;
	len = ft_strlen(map->array[y]);
	while (map->array[y])
	{
		if ((int) ft_strlen(map->array[y++]) != len)
			return (1);
	}
	map->max = (t_point) {len, y};
	map->player_pos = ft_findchr_2d(map, 'P');
	map->collectible_count = ft_countchar_2d(map, 'C');
	return (0);
}
