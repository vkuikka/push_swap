/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:54:25 by vkuikka           #+#    #+#             */
/*   Updated: 2020/01/27 17:54:45 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	//remove

void	ft_swap_ps(unsigned *stack, unsigned len)
{
	unsigned	tmp;

	if (len < 2)
	{
		ft_putstr("\n\tERROR swap stack length inclomplete: ");
		ft_putnbr(len);
		write(1, "\n", 1);
		exit(1);
	}
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	ft_ss(unsigned *stack1, unsigned *stack2, unsigned len1, unsigned len2)
{
	ft_swap_ps(stack1, len1);
	ft_swap_ps(stack2, len2);
}

void	ft_push(unsigned *stack, unsigned *dest, unsigned len1, unsigned len2)
{
	unsigned		i;
	unsigned		tmp;

	i = 0;
	if (len1)
		tmp = stack[0];
	else
	{
		ft_putstr("\n\tERROR pushing from epmty stack!\n");
		exit(1);
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
	//if (len1)
	dest[0] = tmp;
}
