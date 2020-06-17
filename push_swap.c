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
#include <stdio.h>

void	ft_putinfo(unsigned len1, unsigned len2, unsigned *ar1, unsigned *ar2, unsigned i)
{
	ft_putstr("i = ");
	ft_putnbr(i);
	ft_putstr("\tlen1: ");
	ft_putnbr(len1);
	ft_putstr("\t\tlen2: ");
	ft_putnbr(len2);
	ft_putstr("\n");
	ft_putstr("\t1: ");
	if (len1 > 0)
		ft_putnbr_arr((int**)&ar1, 1, len1);
	else
		ft_putstr("empty\n");
	ft_putstr("\t2: ");
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
	unsigned		len1;
	unsigned		len2;

	len1 = len;
	len2 = 0;

	ft_putnbr_arr((int**)&st1, 1, len);
	ft_putstr("\n");

	/*

	0 1 4 2 3

	1 2 0 3 4

	4 4 4 0 1 2 3 4 4 4


	6 4 5 4 0 1 2 3

	5 6 4 0 1 2 3 4

	0 1 2 3 4 5 6
	4
	5 6 0 1 2 3 4
	4


	0 5 1 4 2 3

	4 3 2 1 0

	0 1 2
	0 2 1
	1 2 0
	1 0 2
	2 0 1
	2 1 0

	*/

	/*

go left to right if number is too big put it in stack2 if its too small ignore it at the same time put numbers from stack2 to stack1 and swap if its close
go right to left if number is too small put it in stack2 if its too big ignore it at the same time put numbers from stack2 to stack1 and swap if its close

	*/

	int i = 0;

	while (i <= len)
	{
		if (st1[0] == i + 1 && st1[1] < i + 1 && !(len2 && st2[0] == i))
			ft_swap_ps(st1, len1);
		else if (st1[0] > i)
		{
			printf("push away: %d index: %d\n", st1[0], i);
			ft_push(st1, st2, len1, len2);
			if (len2 > 1)
				ft_swap_ps(st2, len2);
			len1--;
			len2++;
		}


		if (len2 && st2[0] == i)
		{
			printf("push back: %d index: %d\n", st2[0], i);
			ft_rotate(st1, len1);
			ft_push(st2, st1, len2, len1);
			len2--;
			len1++;
		}
		else
		{
			if (st1[0] <= i)
			{
				ft_rotate(st1, len1);
				// i++;
			}
			if (len2 > 1 && st2[0] < i)
				ft_rotate(st2, len2);
		}
		i++;
		// else if (i < len1)
		// 	ft_rotate(st1, len1);
		// else if (len2 > 1 && st2[0] < i)
		// 	ft_rotate(st2, len2);
		ft_putinfo(len1, len2, st1, st2, i);
		if (i == len)
			break;
	}
	ft_rotate(st1, len1);


	ft_putinfo(len1, len2, st1, st2, -1);
	ft_putnbr_arr((int**)&st1, 1, len1);
	return (1);

	ft_putstr("!!!!!!!!!!!!!!!!!!!!!SWITCH!!!!!!!!!!!!!!!!!!!!!!!!!\n");

	int asd = 0;
	while (i > -1)
	{
		asd = 0;
		if (len2 && st2[0] == i)
		{
			if (st1[0] != st1[1] - 1)
				ft_rotate(st1, len1);
			printf("push back: %d index: %d\n", st2[0], i);
			ft_push(st2, st1, len2, len1);
			len2--;
			len1++;
			asd = 1;
		}

		if (st1[0] < i)
		{
			printf("push away: %d index: %d\n", st1[0], i);
			ft_push(st1, st2, len1, len2);
			if (len2 > 1)
				ft_swap_ps(st2, len2);
			len1--;
			len2++;
			ft_rrotate(st1, len1);
		}

		if (!asd)
		{
			if (st1[0] >= i && !(i <= 1))
			{
				ft_rrotate(st1, len1);
				// i--;
			}
			if (len2 > 1 && st2[0] < i)
				ft_rrotate(st2, len2);
			i--;
		}
		// else if (i < len1)
		// 	ft_rotate(st1, len1);
		// else if (len2 > 1 && st2[0] < i)
		// 	ft_rotate(st2, len2);
		ft_putinfo(len1, len2, st1, st2, i);
	}
	
	ft_putinfo(len1, len2, st1, st2, -1);
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
