/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:41:33 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/28 14:03:37 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!haystack && !needle) || (!haystack[0] && needle[0]))
		return (NULL);
	if (!ft_strlen(needle))
		return ((char *) haystack);
	while (i < len && needle[j] && haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j]
			&& i + j < len && needle[j]
			&& haystack[i + j])
			j++;
		if (!needle[j])
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	haystack[] = "aaaaaaaa";
	char	needle[] = "aaaaa";
	int		len = -1000;
	printf("tf = %s\n", strnstr(haystack, needle, len));
	printf("ft = %s\n", ft_strnstr(haystack, needle, len));
	return (0);
}*/
