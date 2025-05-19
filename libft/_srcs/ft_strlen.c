/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:37:27 by lspiteri          #+#    #+#             */
/*   Updated: 2025/04/09 20:41:24 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <string.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%lu\n", ft_strlen(argv[1]));
	printf("%lu\n", strlen(argv[1]));
	return (0);
}
*/
