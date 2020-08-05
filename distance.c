/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:25:09 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/05 15:56:45 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int			ft_push_dist(unsigned *st1, unsigned len1, unsigned number_to_push)
{
	int	dist;
	int i;

	i = 1;
	dist = 0;
	if (number_to_push < st1[0] && number_to_push > st1[len1 - 1])
		return (0);
	if (number_to_push < st1[ft_find_smallest(st1, len1)])
	{
		dist = ft_find_smallest(st1, len1);
		if (dist > len1 / 2)
			return (dist - len1);
		return (dist);
	}
	while (i < len1)
	{
		// printf("%d ", i);
		if (number_to_push < st1[i] && number_to_push > st1[i - 1])
		{
			dist = i;
			break;
		}
		i++;
	}
	// printf("\n");
	i = 1;
	while (i < len1)
	{
		// printf("%d ", i);
		if (number_to_push < st1[len1 - i] && number_to_push > st1[len1 - i - 1])
			if (i < ft_abs(dist))
			{
				dist = i * -1;
				break ;
			}
		i++;
	}
	// printf("\t%d\n", dist);
	return (dist);
}

/*
**	the best move is to rotate to the index ft_find_move returns
*/

int			ft_find_move(unsigned *st1, unsigned *st2, unsigned len1, unsigned len2)
{
	int		i;
	int		dist;
	int		best_dist;
	int		best_rot;
	
	int		first = st2[0];

	i = 0;
	best_rot = 0;
	best_dist = INT32_MAX;
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
