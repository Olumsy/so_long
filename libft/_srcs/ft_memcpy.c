/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:13:35 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/28 13:57:47 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest0;
	const char	*src0;

	if (!dest && !src)
		return ((void *) n);
	dest0 = dest;
	src0 = src;
	i = 0;
	while (i < n)
	{
		dest0[i] = src0[i];
		i++;
	}
	return (dest0);
}
/*
	if (!dest || !src)
		return (NULL);
*/
/*
#include <string.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	char a[20] = "bon";
	char b[10] = "jour";
	ft_memcpy(a,b,3);
	printf("%s\n", a);
	return (0);
}
*/
