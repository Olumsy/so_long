/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:25:01 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/28 13:56:57 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *str0, int c0)
{
	size_t			i;
	char			*str;
	unsigned char	c;

	c = (unsigned char) c0;
	str = (char *)str0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (str[i] == c)
		return (str + i);
	return (NULL);
}
/*
int	main(int argc, char **argv)
{
	char str[] = "abcdefghijklmnopqrstuvwxyz";

	printf("%c\n", 357);
	printf("%p\n", ft_strchr("teste", 357));
	return (0);
}
*/
