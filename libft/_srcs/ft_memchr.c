/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:16:57 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/14 17:15:31 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str0, int c0, size_t n)
{
	size_t			i;
	unsigned char	c;
	unsigned char	*str;

	i = 0;
	c = (unsigned char)c0;
	str = (unsigned char *)str0;
	while (i < n)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	str[] = "abcdefgh";
	printf("tf = %s\n", memchr(str, argv[1][0], 8));
	printf("ft = %s\n", ft_memchr(str, argv[1][0], 8));
	return (0);
}*/
