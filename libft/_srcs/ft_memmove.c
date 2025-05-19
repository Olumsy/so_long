/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:32:49 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/25 18:46:03 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memmove(void *dst0, const void *src0, size_t len)
{
	size_t			i;
	char			*dst;
	const char		*src;

	i = 0;
	src = src0;
	dst = dst0;
	if (!dst0 && !src0)
		return (NULL);
	if (src < dst && src > dst - len)
	{
		i = len;
		while (i-- > 0 && src[i])
			dst[i] = src[i];
		return (dst);
	}
	while (i < len)
	{
		dst[i] = src[i];
		i ++;
	}
	return (dst);
}
//duplicate src to handle overlap
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	a[] = "abcdefghijklmnop";
	char	b[] = "abcdefghijklmnop";
	
	memmove(&a[2], a, 10);
	ft_memmove(&b[2], b, 10);
	printf("tf %s\n", a);
	printf("ft %s\n", b);
	return (0);
}*/
