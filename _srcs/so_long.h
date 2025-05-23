
#ifndef SO_LONG_H
#define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include "./structures.h"
# include "./../libft/_srcs/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void	ft_map_init(t_map *map);
int		ft_read_map(t_map *map, int fd);

#endif
