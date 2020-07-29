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

void	ft_putstack(unsigned *stack, unsigned len, int rot_index, int direction)
{
	int		i;

	for (int stack_index = 0; stack_index < len; stack_index++)
	{
		i = stack_index;
		if (direction == 0)
		{
			i = i - rot_index;
			if (i < 0)
				i = (len - 1) + i;
		}
		else
		{
			i = i + rot_index;
			if (i > len - 1)
				i = i - (len - 1);
		}
		if (stack[stack_index] == i)
			printf("\033[0;32m%d ", stack[stack_index]);
		else if (stack[stack_index] < i)
			printf("\033[0;33m%d ", stack[stack_index]);
		else if (stack[stack_index] > i)
			printf("\033[0;31m%d ", stack[stack_index]);
	}
	printf("\n");
}

static int		ft_push_swap(unsigned *st1, unsigned *st2, unsigned len)
{
	unsigned		len1;
	unsigned		len2;
	int				i;

	len1 = len;
	len2 = 0;
	i = 0;
 
	int err = 0;
	while (i < len || len2)
	{
		err++;
		if (err >= len * 2)
		{
			printf("error: loop 1 does not end\n");
			return (0);
		}
		printf("\033[0;34m%d: ", i);
		ft_putstack(st1, len1, i, 1);
		printf("\033[0;34m%d: ", i);
		ft_putstack(st2, len2, i, 1);
		printf("\n");
		if (len2 && st2[0] == i)		//push back
		{
			ft_push(st2, st1, len2, len1);
			moves++;
			push_moves++;
			len2--;
			len1++;
			ft_rotate(st1, len1);
			moves++;
		}
		else if (st1[0] > i)		//push away
		{
			ft_push_order(st1, st2, len1, len2);
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

	ft_putstack(st1, len1, 0, 1);
	printf("\033[0;0mtotal:\t\t%d\npush:\t\t%d\nst1 ord:\t%d\nst2 ord:\t%d\n\n", moves, push_moves, st1_ordering_moves, st2_ordering_moves);
	ft_putstr("!!!!!!!!!!!!!!!!!!!!!SWITCH!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");

	i = len - 1;

	err = 0;
	while (!(ft_check_order(st1, len1) && !len2) && i > -1)
	{
		err++;
		if (err >= len * 2)
		{
			printf("error: loop 2 does not end\n");
			return (0);
		}

		if (st1[0] < i)		//push away
		{
			ft_push_order_rev(st1, st2, len1, len2);
			len1--;
			len2++;
			if (len2 && st2[0] != i)
			{
				ft_rrotate(st1, len1);
				moves++;
			}
		}
		if (len2 && st2[0] == i)	//push back
		{
			ft_push(st2, st1, len2, len1);
			push_moves++;
			moves++;
			len2--;
			len1++;
		}
		printf("\033[0;34m%d: ", i);
		ft_putstack(st1, len1, i, 0);
		if (st1[0] == i)
		{
			i--;
			if (st1[len1 - 1] != len - 1)
			{
				ft_rrotate(st1, len1);
				moves++;
			}
		}
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
