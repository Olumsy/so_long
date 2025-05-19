/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:05:23 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/18 14:37:45 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
static char	test(unsigned int i, char c)
{
	char	c2;

	c2 = c - i;
	return (c2);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%s\n", ft_strmapi("abcdefghijklmnopqrstuvwxyz", test));
	return (0);
}
*/
