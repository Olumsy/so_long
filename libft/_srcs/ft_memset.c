/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:59:50 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/14 17:20:44 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memset(void *b0, int c, size_t len)
{
	size_t			i;
	unsigned char	*b;

	b = b0;
	i = 0;
	while (i < len)
	{
		b[i++] = c;
	}
	return (b);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char *tomate;
	char *tomate2;
	int	i = 0;
	int	i2 = 0;
	tomate = malloc(sizeof(char) * 10);
	while (i < 10)
		tomate[i++] = 'w';
	tomate2 = malloc(sizeof(char) * 10);
	while (i2 < 10)
		tomate2[i2++] = 'w';
	ft_memset(tomate, '$', 5);
	memset(tomate2, '$', 5);
	printf("ft = %s\n", tomate);
	printf("tf = %s\n", tomate2);
	return (0);
}
*/
