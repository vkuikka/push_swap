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

int		moves;
int		st2_ordering_moves;
int		st1_ordering_moves;
int		push_moves;

void	ft_putstack(unsigned *stack, unsigned len)
{
	for (int asd = 0; asd < len; asd++)
	{
		if (stack[asd] == asd)
			printf("\033[0;32m%d ", stack[asd]);
		else if (stack[asd] < asd)
			printf("\033[0;33m%d ", stack[asd]);
		else if (stack[asd] > asd)
			printf("\033[0;31m%d ", stack[asd]);
	}
	printf("\n");
}

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

static void		ft_push_order_rev(unsigned *st1, unsigned *st2, unsigned len1, unsigned len2)
{
	int		i;

	if (len2 > 2)
	{
		while (!(st1[0] > st2[0] && st1[0] < st2[len2 - 1]) &&											//2  1 0 3
			!(st1[0] < st2[ft_find_smallest(st2, len2)] && ft_find_smallest(st2, len2) == len2 - 1) &&	//0  3 2 1 (stop at this one)
			!(st1[0] > st2[ft_find_biggest(st2, len2)] && ft_find_biggest(st2, len2) == 0))				//3  2 1 0
		{
			ft_rotate(st2, len2);
			st2_ordering_moves++;
			moves++;
			// ft_putstr("\n");
			// ft_putnbr(ft_find_biggest(st2, len2));
			// ft_putstr("\n->");
			// ft_putinfo(len1, len2, st1, st2, -1);
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

static void		ft_push_order(unsigned *st1, unsigned *st2, unsigned len1, unsigned len2)
{
	int		i;

	if (len2 > 2)
	{
		while (!(st1[0] < st2[0] && st1[0] > st2[len2 - 1]) &&										//2  3 0 1  or  1  2 3 0
			!(st1[0] < st2[ft_find_smallest(st2, len2)] && ft_find_smallest(st2, len2) == 0) &&		//0  1 2 3
			!(st1[0] > st2[ft_find_biggest(st2, len2)] && ft_find_biggest(st2, len2) == len2 - 1))	//3  0 1 2
		{
			ft_rotate(st2, len2);
			st1_ordering_moves++;
			moves++;
			// ft_putinfo(len1, len2, st1, st2, -1);
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

static int		ft_push_swap(unsigned *st1, unsigned *st2, unsigned len)
{
	unsigned		len1;
	unsigned		len2;

	len1 = len;
	len2 = 0;

	// ft_putnbr_arr((int**)&st1, 1, len);
	// ft_putstr("\n");

	/*

go left to right if number is too big put it in stack2 if its too small ignore it at the same time put numbers from stack2 to stack1 and swap if its close
go right to left if number is too small put it in stack2 if its too big ignore it at the same time put numbers from stack2 to stack1 and swap if its close

	*/

	int i = 0;

	while (i < len)
	{
		// if (st1[0] == st1[1] + 1 || (st1[0] == i + 1 && st1[1] < i + 2))
		// if ((st1[0] == i + 1 && st1[1] != st1[0] + 1 && !(len2 && st2[0] == i)) || st1[0] == st1[1] + 1)
		// if (st1[0] == st1[1] + 1)
		// {
		// 	ft_swap_ps(st1, len1);
		// 	// ft_putstr("swapping\n");
		// 	moves++;
		// }
		if (st1[0] > i + 1)
		{
			// printf("push away: %d index: %d\n", st1[0], i);
			ft_push_order(st1, st2, len1, len2);
			len1--;
			len2++;
		}
		if (len2 && st2[0] == i)
		{
			// if (st1[0] == i - 1)
			// {
			// 	ft_putstr("asd\n");
			// 	// ft_putstr("asd\nasd\nasd\nasd\nasd\nasd\nasd\nasd\nasd\nasd\nasd\nasd\nasd\nasd\nasd\nasd\n");
			// 	moves++;
			// 	ft_rotate(st1, len1);
			// }
			// printf("push back: %d index: %d\n", st2[0], i);
			ft_push(st2, st1, len2, len1);
			moves++;
			push_moves++;
			len2--;
			len1++;
		}
		// if (st1[0] <= i)
		{
			ft_rotate(st1, len1);
			moves++;
			i++;
		}
	// ft_putstack(st1, len1);
		// ft_putinfo(len1, len2, st1, st2, i);
	}
	// ft_putnbr_arr((int**)&st1, 1, len1);
	// ft_rotate(st1, len1);
	// moves++;

	// ft_putinfo(len1, len2, st1, st2, -1);

	ft_putstack(st1, len1);
	// ft_putstr("!!!!!!!!!!!!!!!!!!!!!SWITCH!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	// while (st1[len1 - 1] == st1[0] - 1)
	// {
	// 	moves++;
	// 	ft_rrotate(st1, len1);
	// }

	// ft_putnbr(len);
	// ft_putstr("\n");
	i = len - 1;
	// i = len - 1; maybe divisible with 2
	// ft_rrotate(st1, len1);

	// ft_rotate(st1, len1);
	// moves--;

	i = 0;
	ft_rrotate(st1, len1);
	while (!(ft_check_order(st1, len1) && !len2))
	{
		ft_rrotate(st1, len1);
		moves++;
		// ft_putinfo(len1, len2, st1, st2, i);
		ft_putnbr(i);
		ft_putstr(": ");
		i++;
		ft_putstack(st1, len1);
		if (st1[0] != st1[1] - 1)
		{
			ft_push_order_rev(st1, st2, len1, len2);
			len1--;
			len2++;
		}
		while (st2[0] == st1[0] - 1)
		{
			// ft_putstr("push back\n");
			ft_push(st2, st1, len2, len1);
			push_moves++;
			moves++;
			len2--;
			len1++;
		}
	}
	ft_putstack(st1, len1);
	printf("\n\n\033[0;0mtotal:\t\t%d\npush:\t\t%d\nst1 ord:\t%d\nst2 ord:\t%d\n", moves, push_moves, st1_ordering_moves, st2_ordering_moves);
	return(0);


	if (!ft_check_order(st1, len1))
	{
		ft_putstr("not ordered in the end!!!!!!!!!!!!!!\n");
		moves++;
		ft_rrotate(st1, len1);
	}

	ft_putinfo(len1, len2, st1, st2, -1);
	ft_putnbr_arr((int**)&st1, 1, len1);
	ft_putstr("\n");
	ft_putnbr(moves);
	ft_putstr("\n");
	return (1);
}

int		main(int argc, char **argv)
{
	int			*buffer;
	unsigned	*stack1;
	unsigned	*stack2;
	unsigned	i;

	moves = 0;
	push_moves = 0;
	st1_ordering_moves = 0;
	st2_ordering_moves = 0;

	if (argc < 2)
	{
		ft_putstr("more arguments needed\n");
		return (0);
	}
	argc--;
	if (!(buffer = (int *)malloc(sizeof(int) * argc)) ||
		!(stack2 = (unsigned *)malloc(sizeof(unsigned) * argc)))
		return (0);
	ft_bzero(stack2, argc);
	i = -1;
	while (++i < argc)
		buffer[i] = ft_atoi(argv[i + 1]);
	stack1 = ft_simplify(buffer, argc);
	ft_push_swap(stack1, stack2, argc);
	return (0);
}
