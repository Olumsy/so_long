/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:41:22 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/14 17:14:12 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%d\n", ft_isdigit(argv[1][0]));
	printf("%d\n", isdigit(argv[1][0]));
	return (0);
}
*/
