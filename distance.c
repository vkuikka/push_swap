/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:25:09 by vkuikka           #+#    #+#             */
/*   Updated: 2020/07/29 17:30:18 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int		ft_dist_push(unsigned *st1, unsigned *st2, unsigned len1, unsigned len2)
{
	int		dist;
	int		i;

	i = 1;
	dist = 0;
	if (st1[0] != st1[1] - 1 && st1[0] != st1[len1 - 1] + 1)
		return (0);
	while (i < len1)
	{
		if (st1[i] != st1[i + 1] - 1 &&
			st1[i] != st1[i - 1] + 1)
		{
			dist = i;
			break;
		}
		i++;
	}
	printf("\033[0;0mrots to push: %d or ", i);
	i = 2;
	while (i < len1)
	{
		if (st1[len1 - i] != st1[len1 - i - 1] + 1 &&
			st1[len1 - i] != st1[len1 - i + 1] - 1 &&
			i < ft_abs(dist))
		{
			dist = i * -1;
			break ;
		}
		i++;
	}
	printf("%d -> %d\n", i * -1, dist);
	return (dist);
}

int		ft_dist_pull(unsigned *st1, unsigned *st2, unsigned len1, unsigned len2)
{
	return (9999);
}

