/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_iteration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:28:33 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/23 18:22:18 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_error(unsigned *stack, unsigned len)
{
	unsigned	i;
	unsigned	current_number;

	i = 1;
	current_number = stack[0];
	while (i < len)
	{
		if (stack[i] != current_number + 1)
			return (i);
		i++;
	}
	return (i);
}

int		ft_find_biggest(unsigned *stack, unsigned len)
{
	unsigned	biggest;
	unsigned	i;

	i = 1;
	biggest = 0;
	while (i < len)
	{
		if (stack[i] > stack[biggest])
			biggest = i;
		i++;
	}
	return (biggest);
}

int		ft_find_smallest(unsigned *stack, unsigned len)
{
	unsigned	smallest;
	unsigned	i;

	i = 1;
	smallest = 0;
	while (i < len)
	{
		if (stack[i] < stack[smallest])
			smallest = i;
		i++;
	}
	return (smallest);
}

int		ft_find_smallest_signed(int *stack, unsigned len)
{
	unsigned	smallest;
	unsigned	i;

	i = 1;
	smallest = 0;
	while (i < len)
	{
		if (stack[i] < stack[smallest])
			smallest = i;
		i++;
	}
	return (smallest);
}

int		ft_check_order(unsigned *stack, unsigned len)
{
	unsigned	i;

	i = 1;
	while (i < len)
	{
		if (stack[i] < stack[i - 1])
			return (0);
		i++;
	}
	return (1);
}
