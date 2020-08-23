/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:08:48 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/23 18: 0:27by vkuikka          ###   ########.fr       */
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
	unsigned		i;
	unsigned		num;

	num = stack[0];
	for (unsigned stack_index = 0; stack_index < len; stack_index++)
	{
		i = stack_index;
		if (stack[stack_index] < num)
			printf("\033[0;31m%d ", stack[stack_index]);	//red
		else if (stack[stack_index] >= num)
		{
			num = stack[stack_index];
			printf("\033[0;32m%d ", stack[stack_index]);	//green
		}
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
			ft_rotate(stack, len, "ra\n");
			dist--;
		}
		else
		{
			ft_rrotate(stack, len, "rra\n");
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
			ft_rrotate(stack, len, "rra\n");
			tmp++;
		}
		else if (tmp < len / 2)
		{
			ft_rotate(stack, len, "ra\n");
			tmp--;
		}
		moves++;
	}
}

static void		ft_deal_three(unsigned *st1, unsigned *len1)
{
	if (st1[0] < st1[1])
		ft_rrotate(st1, *len1, "rra\n");
	else if (st1[0] > st1[1] && st1[0] < st1[2])
		ft_swap_ps(st1, *len1, "sa\n");
	else if (st1[0] > st1[1] && st1[0] > st1[2])
		ft_rotate(st1, *len1, "ra\n");
	else if (st1[0] < st1[1] && st1[0] > st1[2])
		ft_rrotate(st1, *len1, "rra\n");
	moves++;
}

static int		ft_push_stack2(unsigned *st1, unsigned *st2, unsigned *len1, unsigned *len2)
{
	unsigned	first;
	int			len;

	len = *len1;
	first = st1[0];
	ft_optimize_start(st1, *len1);
	while (!ft_check_order(st1, *len1))
	{
		if (*len1 <= 3 && !ft_check_order(st1, *len1))
			ft_deal_three(st1, len1);
		else if (*len2 && st2[0] > st1[*len1 - 1])
		{
			ft_putstr("pa\n");
			ft_push(st2, st1, len2, len1);
			push_moves++;
			moves++;
		}
		else if (st1[0] != first && st1[0] < st1[*len1 - 1])
		{
			ft_putstr("pb\n");
			ft_push(st1, st2, len1, len2);
			push_moves++;
			moves++;
		}
		else
		{
			if (*len2 > 1)
			{
				ft_rr(st1, st2, *len1, *len2);
				ft_putstr("rr\n");
			}
			else
				ft_rotate(st1, *len1, "ra\n");
			moves++;
		}
	}
	return (1);
}

static int		ft_push_swap(unsigned *st1, unsigned *st2, unsigned len)
{
	unsigned		len1;
	unsigned		len2;
	unsigned		i;
	int				dist;

	len1 = len;
	len2 = 0;
	dist = 0;
	ft_push_stack2(st1, st2, &len1, &len2);
	while (len2)
	{
		dist = ft_find_move(st1, st2, len1, len2);
		i = -1;
		while (++i < (unsigned)ft_abs(dist))
		{
			if (dist > 0)
				ft_rotate(st2, len2, "rb\n");
			else if (dist < 0)
				ft_rrotate(st2, len2, "rrb\n");
			st2_ordering_moves++;
			moves++;
		}
		dist = ft_push_dist(st1, len1, st2[0]);
		i = -1;
		while (++i < (unsigned)ft_abs(dist))
		{
			if (dist > 0)
				ft_rotate(st1, len1, "ra\n");
			else if (dist < 0)
				ft_rrotate(st1, len1, "rra\n");
			st1_ordering_moves++;
			moves++;
		}
		ft_push(st2, st1, &len2, &len1);
		ft_putstr("pa\n");
		push_moves++;
		moves++;
	}
	ft_rot_start(st1, len1);
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
