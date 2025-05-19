/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:14:49 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/25 18:43:08 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int str)
{
	if ((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z'))
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%d\n", ft_isalpha(argv[1][0]));
	printf("%d", isalpha(argv[1][0]));
	return (0);
}
*/
