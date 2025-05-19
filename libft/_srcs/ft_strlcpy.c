/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:28:49 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/21 14:29:37 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst0, const char *src0, size_t dstsize)
{
	size_t		i;
	char		*dst;
	const char	*src;

	i = 0;
	dst = dst0;
	src = src0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <string.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	char src[] = "aa";
    char dst[3] = "";
    size_t len = strlcpy(dst, src, 0);

    printf("Return value: %zu\n", len);
    printf("Destination buffer: %s\n", dst);
	char src1[] = "aa";
    char dst1[3] = "";
    size_t len1 = ft_strlcpy(dst1, src1, 0);

    printf("Return value: %zu\n", len1);
    printf("Destination buffer: %s\n", dst1);

	return (0);
}*/
