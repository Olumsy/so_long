/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:39:21 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/18 16:15:45 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*
static void	test(unsigned int i, char *c)
{
	*c += 1;
}

#include <stdio.h>
int	main(void)
{
	char a[] = "abc";
	ft_striteri(a, test);
	printf("%s\n", a);
	return (0);
}
*/
