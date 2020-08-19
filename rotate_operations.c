/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:57:47 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/19 14:42:41 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_rotate(unsigned *stack, unsigned len)
{
	unsigned		first;
	unsigned		i;

	if (len < 2)
	{
		ft_putstr("\tERROR stack empty in rotate\n");
		return (0);
	}
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
	if (!ft_rotate(stack1, len1))
		return (0);
	if (!ft_rotate(stack2, len2))
		return (0);
	return (1);
}

int		ft_rrotate(unsigned *stack, unsigned len)
{
	unsigned		last;
	unsigned		i;

	if (len < 2)
	{
		ft_putstr("\tERROR stack empty in reverse rotate\n");
		return (0);
	}
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
	if (!ft_rrotate(stack1, len1))
		return (0);
	if (!ft_rrotate(stack2, len2))
		return (0);
	return (1);
}