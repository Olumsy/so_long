
#include "./so_long.h"

int	ft_read_map(t_map *map, int fd)
{
	int		len;
	int		total_len;
	char	*temp;

	//secu
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
