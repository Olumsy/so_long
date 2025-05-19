/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:52:48 by lspiteri          #+#    #+#             */
/*   Updated: 2024/10/28 15:46:22 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

static int	get_end(char const *s1, char const *set, int end)
{
	int	i;

	i = 0;
	if (!s1[0])
		return (0);
	while (s1[end + i])
	{
		if (!is_in((char *) set, s1[end + i]))
		{
			end += i;
			i = 0;
		}
		i++;
	}
	return (end + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (is_in((char *) set, s1[start]))
		start++;
	len = get_end(s1, set, start) - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	ft_strtrim("", "afafa");
	return (0);
}
*/
