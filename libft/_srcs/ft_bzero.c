/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:55:50 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/18 18:38:46 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*sbis;

	sbis = s;
	i = 0;
	while (i < n)
		sbis[i++] = '\0';
}
/*
#include <stdio.h>
int	main()
{
	char 	*tomate;
	int		i;

	i = 0;
	tomate = malloc(sizeof(char) * 10);
	while (i < 10)
		tomate[i++] = 'f';
	ft_bzero(tomate, 5);
	printf("%s", tomate);
	return (0);
}*/
