/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:22:39 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/28 12:46:35 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
/*
char	*ft_itoa(int n0)
{
	long	n;
	int		neg;
	int		count;
	char	*str;

	n = (long) n0;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	count = count_digit(n) + neg;
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		return (ft_strlcpy(str, "0", 2), str);
	if (n == 2147483648)
		return (ft_strlcpy(str, "-2147483648", 12), str);
	if (neg)
		str[0] = '-';
	str[count--] = '\0';
	while (count >= neg)
	{
		str[count--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
*/

char	*ft_itoa(int n)
{
	int		neg;
	char	*str;
	int		count;

	count = count_digit(n);
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		return (ft_strlcpy(str, "0\0", 2), str);
	if (n == -2147483648)
		return (ft_strlcpy(str, "-2147483648\0", 12), str);
	neg = (n < 0);
	if (neg)
		n = -n;
	str[count--] = '\0';
	while (count >= neg)
	{
		str[count--] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%s\n", ft_itoa(-15911212));
	return (0);
}
*/
