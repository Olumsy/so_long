
#ifndef SO_LONG_H
#define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include "./structures.h"
# include "./textures.h"
# include "./../libft/_srcs/libft.h"
# include "./../minilibx-linux/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define SPRITE_ORDER "01ECP"
# define SPRITE_SIZE 64

void	ft_map_init(t_map *map);
int		ft_read_map(t_map *map, int fd);
int		ft_backtracking(t_map *map);
int		ft_parsing(t_map *map);
int		player_movement(int	a);
t_point	ft_sum_point(t_point a, t_point b);
int		ft_key_listener(int	keycode, t_context *context);
int		ft_draw_game(t_context context, t_point start);

t_point ft_findchr_2d(t_map *map, char c);
char	**ft_strdup_2d(t_map *map);
int		ft_countchar_2d(t_map *map, char c);
#endif
