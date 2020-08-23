/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:25:09 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/23 18:21:14 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int			ft_push_dist(unsigned *st1, unsigned len1, unsigned number_to_push)
{
	unsigned	dist;
	unsigned	i;

	i = 0;
	dist = 0;
	if (number_to_push < st1[0] && number_to_push > st1[len1 - 1])
		return (0);
	if (number_to_push < st1[ft_find_smallest(st1, len1)])
	{
		dist = ft_find_smallest(st1, len1);
		return (dist > len1 / 2 ? dist - len1 : dist);
	}
	while (++i < len1)
		if (number_to_push < st1[i] && number_to_push > st1[i - 1])
		{
			dist = i;
			break;
		}
	i = 0;
	while (++i < len1)
		if (number_to_push < st1[len1 - i] &&
			number_to_push > st1[len1 - i - 1] && i < (unsigned)ft_abs(dist))
			return (i * -1);
	return (dist);
}

/*
**	the best move is to rotate to the index ft_find_move returns
*/

int			ft_find_move(unsigned *st1, unsigned *st2, unsigned len1, unsigned len2)
{
	unsigned	i;
	unsigned	dist;
	unsigned	best_dist;
	unsigned	best_rot;

	i = 0;
	best_rot = 0;
	best_dist = 2147483647;
	while (i < len2)
	{
		dist = ft_abs(ft_push_dist(st1, len1, st2[i]));
		if (i <= len2 / 2 && i + dist < best_dist)
		{
			best_dist = i + dist;
			best_rot = i;
		}
		else if (i > len2 / 2 && (len2 - i) + dist < best_dist)
		{
			best_dist = (len2 - i) + dist;
			best_rot = i - len2;
		}
		i++;
	}
	// printf("dist from st2[0]: %d\n", ft_abs(ft_push_dist(st1, len1, first)));
	// printf("best dist found: %d\n", best_dist);
	// // ft_putstack(st1, len1, 0, 1);
	// // ft_putstack(st2, len2, 0, 1);
	// printf("best rotation is %d\n\n", best_rot);
	return (best_rot);
}
