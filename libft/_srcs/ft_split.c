/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:29:18 by lspiteri          #+#    #+#             */
/*   Updated: 2025/04/09 22:46:30 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s[0])
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	if (i > 0 && s[i - 1] != c)
		count++;
	return (count);
}

void	ft_free_arrstr(char ***arr, int i)
{
	while (i >= 0)
	{
		free((*arr)[i]);
		i--;
	}
	free(*arr);
	*arr = NULL;
}

static char	*ft_fill_str(const char *s, char c)
{
	size_t	len;
	char	*temp;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, s, len + 1);
	return (temp);
}

char	**ft_split(const char *s, char c)
{
	int		wc;
	char	**arr;

	wc = 0;
	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			arr[wc] = ft_fill_str(s, c);
			if (!arr[wc])
			{
				ft_free_arrstr(&arr, wc);
				return (NULL);
			}
			s += ft_strlen(arr[wc++]);
		}
	}
	return (arr[wc] = NULL, arr);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
	return (0);
}
*/
