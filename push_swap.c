/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:08:48 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/05 14:41:18 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "libft/includes/libft.h"
#include <stdio.h>

int		moves;
int		st2_ordering_moves;
int		st1_ordering_moves;
int		push_moves;

void	ft_putstack(unsigned *stack, unsigned len, int rot_index, int direction)
{
	int		i;
	int		num;

	num = stack[0];
	for (int stack_index = 0; stack_index < len; stack_index++)
	{
		i = stack_index;
		if (stack[stack_index] < num)
			printf("\033[0;31m%d ", stack[stack_index]);	//red
		else if (stack[stack_index] >= num)
		{
			num = stack[stack_index];
			printf("\033[0;32m%d ", stack[stack_index]);	//green
		}
		// else if (stack[stack_index] > i)
			// printf("\033[0;33m%d ", stack[stack_index]);
	}
	printf("\n");
}

void	ft_optimize_start(unsigned *stack, int len)
{
	int tmp;
	int	i;

	tmp = 0;
	i = 0;
	ft_putstack(stack, len, 0, 1);
	while (i < START_FIND_DIST)
	{
		if (stack[i + 1] < stack[tmp])
			tmp = i + 1;
		else if (stack[len - i - 1] < stack[tmp])
			tmp = len - i - 1;
		i++;
	}
	while (tmp && tmp != len)
	{
		if (tmp >= len / 2)
		{
			ft_rrotate(stack, len);
			tmp++;
		}
		else if (tmp < len / 2)
		{
			ft_rotate(stack, len);
			tmp--;
		}
		moves++;
	}
	ft_putstack(stack, len, 0, 1);
	printf("\n");
}

int			ft_push_back_dist(unsigned *st1, unsigned *st2, unsigned len1, unsigned len2)
{
	int	dist;
	int i;

	i = 1;
	dist = 0;
	if (st1[0] < st2[0] && st1[0] > st2[len2 - 1])
		return (0);
	while (i < len2)
	{
		printf("%d", i);
		if (st1[0] < st2[i] && st1[0] > st2[i - 1])
		{
			dist = i;
			break;
		}
		i++;
	}
	printf("\n");
	i = 1;
	while (i < len2)
	{
		printf("%d", i);
		if (st1[0] < st2[len2 - i] && st1[0] > st2[len2 - i - 1])
			if (i < ft_abs(dist))
			{
				dist = i * -1;
				break ;
			}
		i++;
	}
	printf("\t%d\n", dist);
	return (dist);
}

static int		ft_check_spot_order(unsigned *stack, unsigned len)
{
	int		biggest_num;
	int		i;

	biggest_num = ft_find_biggest(stack, len);
	i = ft_find_smallest(stack, len);
	// if (!(i == 0 && biggest_num == len - 1) || !(biggest_num == i + 1))
	// {
	// 	printf("\n~~~~~~~~~~~\n");
	// 	return (0);
	// }
	// ft_putstack(stack, len, 0, 1);
	printf("\n\nlen %d checking: \n", len);
	int err = 0;
	while (stack[i] == stack[i + 1] - 1)
	{
		err++;
		if (err > len * 2)
			exit (1);
		printf("%d ", i);

		i++;
		if (i == len - 1)
		{
			if (stack[i] != stack[0] - 1)
			{
				printf("not ordered\n");
				return (0);
			}
			i = 0;
		}
		if (i == biggest_num)
		{
			printf("ordered\n");
			return (1);
		}
	}
	printf("not ordered\n");
	return (0);
}

static int		ft_push_swap(unsigned *st1, unsigned *st2, unsigned len)
{
	unsigned		len1;
	unsigned		len2;
	unsigned		i;
	int				tmp;

	len1 = len;
	len2 = 0;
	i = 0;

	/*

left to right if number is too big put it in stack2 if its too small ignore it at the same time put numbers from stack2 to stack1 and swap if its close
right to left if number is too small put it in stack2 if its too big ignore it at the same time put numbers from stack2 to stack1 and swap if its close

left to right if number is not in order take it out
put everything back

	*/
	i = 0;
	ft_optimize_start(st1, len1);
	int first = st1[0];

	while (!ft_check_order(st1, len1))
	{
		if (i > len * 2)
			exit(1);
		printf("\033[0;34m%d: ", i);
		ft_putstack(st1, len1, i, 1);
		if (st1[0] > st1[1] && st1[1] != first)
			ft_swap_ps(st1, len1);
		else if (st1[1] == first)
		{
			ft_rotate(st1, len1);
			break;
		}

		if (len2 && st2[0] > st1[len - 1])
		{
			// printf("push back: %d index: %d\n", st2[0], i);
			ft_push(st2, st1, len2, len1);
			moves++;
			push_moves++;
			len2--;
			len1++;
			ft_rotate(st1, len1);
			moves++;
		}
		else if (st1[0] != first && (st1[0] < st1[len1 - 1]))	// || st1[0] > (st1[len - 1] + 1) * 2))
		{
			// printf("push away: %d index: %d\n", st1[0], i);
			// ft_push_order_rev(st1, st2, len1, len2);
			// ft_push_order(st1, st2, len1, len2);
			ft_push(st1, st2, len1, len2);
			moves++;
			push_moves++;
			len1--;
			len2++;
			i++;
		}
		else
		{
			ft_rotate(st1, len1);
			moves++;
			i++;
		}
	}

	printf("\n");
	ft_putstack(st1, len1, 0, 1);
	ft_putstack(st2, len2, 0, 1);
	printf("\n");
	printf("\033[0;0mtotal:\t\t%d\npush:\t\t%d\nst1 ord:\t%d\nst2 ord:\t%d\n\n", moves, push_moves, st1_ordering_moves, st2_ordering_moves);
	// ft_putstr("!!!!!!!!!!!!!!!!!!!!!SWITCH!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
	// exit(1);

	i = len - 1;

	int err = 0;
	while (!(ft_check_order(st1, len1) && !len2))
	{
		err++;
		printf("\033[0;34m%d: ", i);
		ft_putstack(st1, len1, 0, 1);
		if (err == len * 2)
			return (0);

		if (len2 && st2[0] < st1[0])	//push back
		{
			ft_push(st2, st1, len2, len1);
			push_moves++;
			moves++;
			len2--;
			len1++;
			// ft_rrotate(st1, len1);
			// moves++;
		}
		printf("\033[0;34m%d: ", i);
		ft_putstack(st1, len1, i, 0);
		ft_rrotate(st1, len1);
		moves++;
	}
	ft_putstack(st1, len1, 0, 1);
	printf("\033[0;0mtotal:\t\t%d\npush:\t\t%d\nst1 ord:\t%d\nst2 ord:\t%d\n\n", moves, push_moves, st1_ordering_moves, st2_ordering_moves);
	return(0);
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
