/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:57:34 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/22 11:57:07 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dstlen;
	size_t		srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= size)
		return (srclen + size);
	if (srclen < size - dstlen)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, size - dstlen);
		dst[size - 1] = '\0';
	}
	return (dstlen + srclen);
}
/*
#include <string.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	dest[14] = "a";
	ft_strlcat(dest, "lorem ipsum", 15);a
    write(1, "\n", 1);
    write(1, dest, 15);
	return (0);
}
*/
