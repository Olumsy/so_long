/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:02:53 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/14 17:14:59 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int var)
{
	if (var >= 32 && var <= 126)
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%d\n", ft_isprint(argv[1][0]));
	printf("%d\n", isprint(argv[1][0]));
	return (0);
}
*/
