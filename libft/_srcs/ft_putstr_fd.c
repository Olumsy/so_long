/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:44:52 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/18 18:00:55 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main(int ac, char **av)
{
	ft_putstr_fd(av[1], open("test.txt", O_WRONLY));
	return (0);
}
*/
