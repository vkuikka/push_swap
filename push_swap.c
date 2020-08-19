/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:08:48 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/19 16:37:45 by vkuikka          ###   ########.fr       */
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

void	ft_rot_start(unsigned *stack, int len)
{
	int		dist;

	dist = 0;
	while (dist <= len / 2)
	{
		if (stack[dist] == 0)
			break;
		if (stack[len - dist] == 0 && (dist *= -1))
			break;
		dist++;
	}
	while (ft_abs(dist))
	{
		if (dist > 0)
		{
			ft_putstr("ra\n");
			ft_rotate(stack, len);
			dist--;
		}
		else
		{
			ft_putstr("rra\n");
			ft_rrotate(stack, len);
			dist++;
		}
		moves++;
	}
}

void	ft_optimize_start(unsigned *stack, int len)
{
	int tmp;
	int	i;

	tmp = 0;
	i = 0;
	while (i < (len > 30 ? START_FIND_DIST : len / 4))
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
			ft_putstr("rra\n");
			ft_rrotate(stack, len);
			tmp++;
		}
		else if (tmp < len / 2)
		{
			ft_putstr("ra\n");
			ft_rotate(stack, len);
			tmp--;
		}
		moves++;
	}
}

static int		ft_push_swap(unsigned *st1, unsigned *st2, unsigned len)
{
	unsigned		len1;
	unsigned		len2;
	unsigned		i;
	int				tmp;
	int				first;
	
	first = st1[0];

	len1 = len;
	len2 = 0;
	i = 0;
	// if (len > 40)
	// ft_putstack(st1, len1, 0, 1);
	ft_optimize_start(st1, len1);

	int err = 0;
	while (!ft_check_order(st1, len1))
	{
		err++;
		if (err == len * len)
		{
			printf("too many loops\n");
			return (0);
		}

		// printf("\n");
		// ft_putstack(st1, len1, 0, 1);
		// ft_putstack(st2, len2, 0, 1);

		if (len1 <= 3 && !ft_check_order(st1, len1))
		{
			if (st1[0] < st1[1])
			{
				ft_putstr("rra\n");
				ft_rrotate(st1, len1);
			}
			else if (st1[0] > st1[1] && st1[0] < st1[2])
			{
				ft_putstr("sa\n");
				ft_swap_ps(st1, len1);
			}
			else if (st1[0] > st1[1] && st1[0] > st1[2])
			{
				ft_putstr("ra\n");
				ft_rotate(st1, len1);
			}
			else if (st1[0] < st1[1] && st1[0] > st1[2])
			{
				ft_putstr("rra\n");
				ft_rrotate(st1, len1);
			}
			moves++;
		}
		else if (len2 && st2[0] > st1[len - 1])
		{
			ft_putstr("pa\n");
			ft_push(st2, st1, len2, len1);	//push back to st1
			push_moves++;
			moves++;
			len2--;
			len1++;
		}
		else if ((st1[0] != first && st1[0] < st1[len1 - 1]))// &&
			// !(!ft_find_smallest(st1, len1) && ft_find_biggest(st1, len1) == len - 1)) ||
			// (st1[len1 - 1] == ft_find_smallest(st1, len1) && st1[len1 - 2] == ft_find_biggest(st1, len1) && st1[0] > st1[1]))
		{
			ft_putstr("pb\n");
			ft_push(st1, st2, len1, len2);
			push_moves++;
			moves++;
			len1--;
			len2++;
		}
		else
		{
			if (len2 > 1)
			{
				// printf("%d rotate both\n", moves);
				ft_putstr("rr\n");
				ft_rr(st1, st2, len1, len2);
			}
			else
			{
				// printf("%d rotate stack 1\n", moves);
				ft_putstr("ra\n");
				ft_rotate(st1, len1);
			}
			moves++;
		}
		// ft_putstack(st1, len1, 0, 1);
	}

	// ft_putstack(st1, len1, 0, 1);
	// ft_putstack(st2, len2, 0, 1);
	// printf("\n");
	// printf("\033[0;0mtotal:\t\t%d\npush:\t\t%d\nst1 ord:\t%d\nst2 ord:\t%d\n\n", moves, push_moves, st1_ordering_moves, st2_ordering_moves);

	int dist = 0;

	err = 0;
	while (len2)
	{
		err++;
		if (err == len * 2)
			return (0);

		// ft_putstack(st1, len1, 0, 1);
		// ft_putstack(st2, len2, 0, 1);
		// printf("\n");

		dist = ft_find_move(st1, st2, len1, len2);
		i = 0;
		while (i < ft_abs(dist))
		{
			if (dist > 0)
			{
				ft_putstr("rb\n");
				ft_rotate(st2, len2);
			}
			else if (dist < 0)
			{
				ft_putstr("rrb\n");
				ft_rrotate(st2, len2);
			}
			moves++;
			st2_ordering_moves++;
			i++;
		}
		dist = ft_push_dist(st1, len1, st2[0]);
		i = 0;
		while (i < ft_abs(dist))
		{
			if (dist > 0)
			{
				ft_putstr("ra\n");
				ft_rotate(st1, len1);
			}
			else if (dist < 0)
			{
				ft_putstr("rra\n");
				ft_rrotate(st1, len1);
			}
			moves++;
			st1_ordering_moves++;
			i++;
		}
		ft_putstr("pa\n");
		ft_push(st2, st1, len2, len1);
		push_moves++;
		moves++;
		len2--;
		len1++;
	}
	ft_rot_start(st1, len1);
	// printf("\033[0;0mtotal:\t\t%d\npush:\t\t%d\nst1 ord:\t%d\nst2 ord:\t%d\n\n", moves, push_moves, st1_ordering_moves, st2_ordering_moves);
	return(0);
}

int		main(int argc, char **argv)
{
	unsigned	*stack1;
	unsigned	*stack2;
	int			*buffer;

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
	if (!(argc = ft_check_input(argv + 1, &buffer, argc)) ||
		!(stack2 = (unsigned *)malloc(sizeof(unsigned) * argc)))
		return (1);
	stack1 = ft_simplify(buffer, argc);
	ft_push_swap(stack1, stack2, argc);
	return (0);
}
