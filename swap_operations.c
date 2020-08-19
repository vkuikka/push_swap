/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:54:25 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/17 17:18:32 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	//remove

int		ft_swap_ps(unsigned *stack, unsigned len)
{
	unsigned	tmp;

	if (len < 2)
	{
		ft_putstr("\n\tERROR swapping stack len < 2!\n");
		return (0);
	}
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	return (1);
}

int		ft_ss(unsigned *stack1, unsigned *stack2, unsigned len1, unsigned len2)
{
	ft_putstr("ss\n");
	if (!ft_swap_ps(stack1, len1))
		return (0);
	if (!ft_swap_ps(stack2, len2))
		return (0);
	return (1);
}

int		ft_push(unsigned *stack, unsigned *dest, unsigned len1, unsigned len2)
{
	unsigned		i;
	unsigned		tmp;

	i = 0;
	if (len1)
		tmp = stack[0];
	else
	{
		ft_putstr("\n\tERROR pushing from epmty stack!\n");
		return (0);
	}
	while(i + 1 < len1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = -404;
	i = len2;
	while (i > 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}
	dest[0] = tmp;
	return (1);
}
