/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:16:33 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/21 17:12:55 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *first0, const void *second0, size_t len)
{
	const char	*first;
	const char	*second;

	first = (const char *) first0;
	second = (const char *) second0;
	while (len--)
	{
		if (*first != *second)
			return ((unsigned char)*first - (unsigned char)*second);
		first++;
		second++;
	}
	return (0);
}
/*
#include "string.h"
#include <stdio.h>
int	main(int argc, char **argv)
{
	char first[] = "abcdefghijklmnopqrstuvwxyz";
	char second[] = "abcdefghijklmnopqrstuvwxyz";
	int	len = 0;
	printf("tf = %d\n", memcmp(first, second, len));
	printf("ft = %d\n", memcmp(first, second, len));
	return (0);
}*/
