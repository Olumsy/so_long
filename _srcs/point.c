/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:20:43 by lspiteri          #+#    #+#             */
/*   Updated: 2025/06/18 20:44:24 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

t_point	ft_sum_point(t_point a, t_point b)
{
	return ((t_point){a.x + b.x, a.y + b.y});
}

int	ft_comp_point(t_point a, t_point b)
{
	return (a.x != b.x || a.y != b.y);
}
