/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:57:47 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/23 18:11:08 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_rotate(unsigned *stack, unsigned len, char *move)
{
	unsigned		first;
	unsigned		i;

	if (len < 2)
	{
		ft_putstr("\tERROR stack empty in rotate\n");
		return (0);
	}
	if (move)
		ft_putstr(move);
	i = 0;
	first = stack[0];
	len--;
	while (i < len)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = first;
	return (1);
}

int		ft_rr(unsigned *stack1, unsigned *stack2, unsigned len1, unsigned len2)
{
	if (!ft_rotate(stack1, len1, NULL))
		return (0);
	if (!ft_rotate(stack2, len2, NULL))
		return (0);
	return (1);
}

int		ft_rrotate(unsigned *stack, unsigned len, char *move)
{
	unsigned		last;
	unsigned		i;

	if (len < 2)
	{
		ft_putstr("\tERROR stack empty in reverse rotate\n");
		return (0);
	}
	if (move)
		ft_putstr(move);
	i = len - 1;
	last = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = last;
	return (1);
}

int		ft_rrr(unsigned *stack1, unsigned *stack2, unsigned len1, unsigned len2)
{
	if (!ft_rrotate(stack1, len1, NULL))
		return (0);
	if (!ft_rrotate(stack2, len2, NULL))
		return (0);
	return (1);
}