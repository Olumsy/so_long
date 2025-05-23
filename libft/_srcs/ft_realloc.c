/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:55:03 by lspiteri          #+#    #+#             */
/*   Updated: 2025/05/01 19:10:53 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_realloc(char *str, int size)
{
	char	*new;
	int		len;

	if (!str)
		return (str = ft_calloc(sizeof(char), size), str);
	if ((int)ft_strlen(str) == size)
		return (str);
	new = ft_calloc(sizeof(char), size);
	if (!new)
		return (free(str), NULL);
	len = ft_strlen(str);
	ft_strlcpy(new, str, len + 1);
	free(str);
	str = NULL;
	return (new);
}
