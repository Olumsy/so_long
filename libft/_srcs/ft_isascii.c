/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:51:15 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/08 14:56:34 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int var)
{
	if (var >= 0 && var <= 127)
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%d\n", ft_isascii(argv[1][0]));
	printf("%d\n", isascii(argv[1][0]));
	return (0);
}
*/
