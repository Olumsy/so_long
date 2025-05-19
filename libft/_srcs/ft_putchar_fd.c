/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:25:12 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/18 17:39:45 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main(int ac, char **argv)
{
	ft_putchar_fd('a', open(argv[1], O_WRONLY) + 1);
	return (0);
}
*/
