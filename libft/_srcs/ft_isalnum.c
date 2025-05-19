/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:44:08 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/14 17:13:17 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int var)
{
	if ((var >= '0' && var <= '9')
		|| (var >= 'a' && var <= 'z')
		|| (var >= 'A' && var <= 'Z'))
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%d\n", ft_isalnum(argv[1][0]));
	printf("%d\n", isalnum(argv[1][0]));
	return (0);
}
*/
