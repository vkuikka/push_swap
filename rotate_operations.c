/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:57:47 by vkuikka           #+#    #+#             */
/*   Updated: 2020/01/27 17:58:09 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(unsigned *stack, unsigned len)
{
	unsigned		first;
	unsigned		i;

	if (len < 2)
	{
		ft_putstr("\n\tERROR stack empty in rotate\n");
		exit(1);
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
}

void	ft_rr(unsigned *stack1, unsigned *stack2, unsigned len1, unsigned len2)
{
	ft_rotate(stack1, len1);
	ft_rotate(stack2, len2);
}

void	ft_rrotate(unsigned *stack, unsigned len)
{
	unsigned		last;
	unsigned		i;

	if (len < 2)
	{
		ft_putstr("\n\tERROR stack empty in reverse rotate\n");
		exit(1);
	}
	i = len - 1;
	last = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = last;
}

void	ft_rrr(unsigned *stack1, unsigned *stack2, unsigned len1, unsigned len2)
{
	ft_rrotate(stack1, len1);
	ft_rrotate(stack2, len2);
}