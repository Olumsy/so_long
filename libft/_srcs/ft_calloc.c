/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:12:46 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/25 16:16:17 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;

	if ((count != 0 && size != 0) && count > SIZE_MAX / size)
		return (NULL);
	p = malloc(size * count);
	if (!p)
		return (NULL);
	ft_memset(p, 0, count * size);
	return (p);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	
	return (0);
}
*/
