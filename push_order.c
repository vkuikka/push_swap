/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:06:54 by vkuikka           #+#    #+#             */
/*   Updated: 2020/07/29 16:23:06 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include <stdio.h>


extern int		moves;
extern int		st2_ordering_moves;
extern int		st1_ordering_moves;
extern int		push_moves;


int			ft_order_dist_rev(unsigned *st1, unsigned *st2, unsigned len1, unsigned len2)
{
	int	dist;
	int i;

	i = 1;
	dist = 0;
	if (st1[0] > st2[0] && st1[0] < st2[len2 - 1])
		return (0);
	while (i < len2)
	{
		printf("%d", i);
		if (st1[0] > st2[i] && st1[0] < st2[i - 1])
		{
			dist = i;
			break;
		}
		i++;
	}
	printf("\n");
	i = 1;
	while (i < len2)
	{
		printf("%d", i);
		if (st1[0] > st2[len2 - i] && st1[0] < st2[len2 - i - 1])
			if (i < ft_abs(dist))
			{
				dist = i * -1;
				break ;
			}
		i++;
	}
	printf("\t%d\n", dist);
	return (dist);
}

void		ft_push_order_rev(unsigned *st1, unsigned *st2, unsigned len1, unsigned len2)
{
	int		i;
	int		dist;

	if (len2 > 2)
	{
		// while (!(st1[0] > st2[0] && st1[0] < st2[len2 - 1]) &&											//2  1 0 3
		// 	!(st1[0] < st2[ft_find_smallest(st2, len2)] && ft_find_smallest(st2, len2) == len2 - 1) &&	//0  3 2 1 (stop at this one)
		// 	!(st1[0] > st2[ft_find_biggest(st2, len2)] && ft_find_biggest(st2, len2) == 0))				//3  2 1 0
		i = 0;
		dist = ft_order_dist_rev(st1, st2, len1, len2);
		while (i < ft_abs(dist))
		{
			if (dist < 0)
				ft_rrotate(st2, len2);
			else
				ft_rotate(st2, len2);
			st2_ordering_moves++;
			moves++;
			i++;
		}
	}
	if (len2 == 2 && ((st2[0] < st2[1] && st1[0] > st2[0] && st1[0] > st2[1]) ||	// 2   0 1
					(st2[0] > st2[1] && st1[0] < st2[0] && st1[0] > st2[1]) ||	// 1   2 0
					(st2[0] < st2[1] && st1[0] < st2[0] && st1[0] < st2[1])))	// 0   1 2
	{
		ft_swap_ps(st2, len2);
		st2_ordering_moves++;
		moves++;
	}

	ft_push(st1, st2, len1, len2);
	push_moves++;
	moves++;
	len2++;

	if (len2 == 3 && (st2[2] > st2[1] && st2[0] < st2[2] && st2[0] > st2[1])) // 1 0 2
	{
		ft_rrotate(st2, len2);
		st2_ordering_moves++;
		moves++;
	}
	if (len2 == 3 && (st2[2] < st2[1] && st2[0] < st2[2] && st2[0] < st2[1])) // 0 2 1
	{
		ft_rotate(st2, len2);
		st2_ordering_moves++;
		moves++;
	}

	i = ft_find_biggest(st2, len2);
	while (i)
	{
		ft_rotate(st2, len2);
		st2_ordering_moves++;
		moves++;
		i--;
	}
}

int			ft_order_dist(unsigned *st1, unsigned *st2, unsigned len1, unsigned len2)
{
	int	dist;
	int i;

	i = 1;
	dist = 0;
	if (st1[0] < st2[0] && st1[0] > st2[len2 - 1])
		return (0);
	while (i < len2)
	{
		printf("%d", i);
		if (st1[0] < st2[i] && st1[0] > st2[i - 1])
		{
			dist = i;
			break;
		}
		i++;
	}
	printf("\n");
	i = 1;
	while (i < len2)
	{
		printf("%d", i);
		if (st1[0] < st2[len2 - i] && st1[0] > st2[len2 - i - 1])
			if (i < ft_abs(dist))
			{
				dist = i * -1;
				break ;
			}
		i++;
	}
	printf("\t%d\n", dist);
	return (dist);
}

void		ft_push_order(unsigned *st1, unsigned *st2, unsigned len1, unsigned len2)
{
	int		i;
	int		dist;

	if (len2 > 2)
	{
		// while (!(st1[0] < st2[0] && st1[0] > st2[len2 - 1]) &&										//2  3 0 1  or  1  2 3 0
		// 	!(st1[0] < st2[ft_find_smallest(st2, len2)] && ft_find_smallest(st2, len2) == 0) &&		//0  1 2 3
		// 	!(st1[0] > st2[ft_find_biggest(st2, len2)] && ft_find_biggest(st2, len2) == len2 - 1))	//3  0 1 2
		i = 0;
		dist = ft_order_dist(st1, st2, len1, len2);
		while (i < ft_abs(dist))
		{
			if (dist < 0)
				ft_rrotate(st2, len2);
			else
				ft_rotate(st2, len2);
			st1_ordering_moves++;
			moves++;
			i++;
		}
	}
	if (len2 == 2 && ((st2[0] > st2[1] && st1[0] > st2[1] && st1[0] > st2[0]) ||	// 2   1 0
					(st2[0] < st2[1] && st1[0] > st2[0] && st1[0] < st2[1]) ||	// 1   0 2
					(st2[0] > st2[1] && st1[0] < st2[0] && st1[0] < st2[1])))	// 0   2 1
	{
		ft_swap_ps(st2, len2);
		st1_ordering_moves++;
		moves++;
	}

	ft_push(st1, st2, len1, len2);
	push_moves++;
	moves++;
	len2++;

	if (len2 == 3 && (st2[2] < st2[1] && st2[0] > st2[2] && st2[0] < st2[1])) // 1 2 0
	{
		ft_rrotate(st2, len2);
		st1_ordering_moves++;
		moves++;
	}
	if (len2 == 3 && (st2[2] > st2[1] && st2[0] > st2[2] && st2[0] > st2[1])) // 2 0 1
	{
		ft_rotate(st2, len2);
		st1_ordering_moves++;
		moves++;
	}

	i = ft_find_smallest(st2, len2);
	while (i)
	{
		ft_rotate(st2, len2);
		st1_ordering_moves++;
		moves++;
		i--;
	}
}

