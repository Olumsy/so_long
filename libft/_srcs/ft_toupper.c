/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:13:42 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/28 13:56:32 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	ft_toupper(int c0)
{
	unsigned char	c;

	if (c0 == -1)
		return (-1);
	c = c0;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char c = 'f';
	printf("%c\n", ft_toupper(argv[1][0]));
	return (0);
}*/
