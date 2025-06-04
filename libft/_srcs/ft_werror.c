
#include "./libft.h"

int	ft_werror(char *s)
{
	return (write(2, s, ft_strlen(s)));
}
