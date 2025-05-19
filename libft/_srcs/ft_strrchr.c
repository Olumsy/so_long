/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:57:42 by lspiteri          #+#    #+#             */
/*   Updated: 2025/02/23 20:01:51 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c0)
{
	ssize_t			i;
	unsigned char	c;

	c = (unsigned char) c0;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)str + i);
		if (i == 0)
			break ;
		i--;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char str[] = "salut";

	printf("%s\n", ft_strrchr(str + 2, 's'));
	return (0);
}
*/
