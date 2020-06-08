/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:08:48 by vkuikka           #+#    #+#             */
/*   Updated: 2020/01/27 17:11:26 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "libft/includes/libft.h"

void	ft_putinfo(unsigned len1, unsigned len2, unsigned *ar1, unsigned *ar2)
{
	ft_putstr("len1: ");
	ft_putnbr(len1);
	ft_putstr("\t\tlen2: ");
	ft_putnbr(len2);
	ft_putstr("\n");
	ft_putstr("1: ");
	if (len1 > 0)
		ft_putnbr_arr((int**)&ar1, 1, len1);
	else
		ft_putstr("empty\n");
	ft_putstr("2: ");
	if (len2 > 0)
		ft_putnbr_arr((int**)&ar2, 1, len2);
	else
		ft_putstr("empty\n");
	ft_putstr("\n");
}

static int		ft_check_order(unsigned	*stack, unsigned len)
{
	int		i;

	i = 1;
	while (i < len)
	{
		if (stack[i] < stack[i - 1])
			return(0);
		i++;
	}
	return(1);
}

static int		ft_push_swap(unsigned *st1, unsigned *st2, unsigned len)
{
	int		len1;
	int		len2;
	int		i = 0;

	len1 = len;
	len2 = 0;

	ft_putnbr_arr((int**)&st1, 1, len);
	ft_putstr("\n");

	while (i < len1 - 1)
	{
		i++;
	}

	ft_putinfo(len1, len2, st1, st2);
	ft_putnbr_arr((int**)&st1, 1, len1);
	return (1);
}

int		main(int argc, char **argv)
{
	unsigned	*stack1;
	unsigned	*stack2;
	int			*buffer;
	unsigned	i;

	if (argc < 2)
	{
		ft_putstr("more arguments needed\n");
		return (0);
	}
	argc--;
	if (!(buffer = (int *)malloc(sizeof(int) * argc)) ||
		!(stack2 = (int *)malloc(sizeof(int) * argc)))
		return (0);
	ft_bzero(stack2, argc);
	i = -1;
	while (++i < argc)
		buffer[i] = ft_atoi(argv[i + 1]);
	stack1 = ft_simplify(buffer, argc);
	ft_push_swap(stack1, stack2, argc);
	return (0);
}
