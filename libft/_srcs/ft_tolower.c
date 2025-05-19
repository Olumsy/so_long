/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:19:57 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/28 13:35:48 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	ft_tolower(int c0)
{
	unsigned char	c;

	if (c0 == -1)
		return (c0);
	c = c0;
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%c\n", ft_tolower(argv[1][0]));
	return (0);
}*/
