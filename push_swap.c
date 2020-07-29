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

// int			ft_order_dist(unsigned *st1, unsigned *st2, unsigned len1, unsigned len2)
// {
// 	int	dist;
// 	int i;

// 	i = 1;
// 	dist = 0;
// 	if (st1[0] < st2[0] && st1[0] > st2[len2 - 1])
// 		return (0);
// 	while (i < len2)
// 	{
// 		printf("%d", i);
// 		if (st1[0] < st2[i] && st1[0] > st2[i - 1])
// 		{
// 			dist = i;
// 			break;
// 		}
// 		i++;
// 	}
// 	printf("\n");
// 	i = 1;
// 	while (i < len2)
// 	{
// 		printf("%d", i);
// 		if (st1[0] < st2[len2 - i] && st1[0] > st2[len2 - i - 1])
// 			if (i < ft_abs(dist))
// 			{
// 				dist = i * -1;
// 				break ;
// 			}
// 		i++;
// 	}
// 	printf("\t%d\n", dist);
// 	return (dist);
// }

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

/*
**	find out if pushing a wrong number to stack2 or pushing a right number from stack2 is closer
**	rotate to where that operation can be done (direction does not matter) and do the operation
**	repeat until order is achieved and rotate zero to the top of the stack
**	can be optimized by finding best order to start with insted of assuming first number or zero is in the correct spot
*/

static int		ft_push_swap(unsigned *st1, unsigned *st2, unsigned len)
{
	unsigned		len1;
	unsigned		len2;
	int				dist = 0;
	int				dist2 = 999;
	int				rotation = 0;
	int				i = 0;

	len1 = len;
	len2 = 0;
 
	int err = 0;
	while (!(ft_check_spot_order(st1, len1) && !len2))
	{
		printf("---------------------------\n");
		ft_putstack(st1, len1, 0, 1);
		// ft_putstack(st2, len2, 0, 1);

		dist = ft_dist_push(st1, st2, len1, len2);
		dist2 = ft_dist_pull(st1, st2, len1, len2);

		i = 0;
		// while (i < ft_abs(dist < dist2 ? dist : dist2))
		printf("rotating: ");
		while (i < ft_abs(dist))
		{
			if ((dist < dist2 ? dist : dist2) < 0)
			{
				ft_rrotate(st1, len1);
				printf("rr ");
			}
			else
			{
				ft_rotate(st1, len1);
				printf("r ");
			}
			i++;
		}
		printf("\nlen1: %d\ndist: %d\n", len1, dist);

		if (dist < dist2 && !ft_check_spot_order(st1, len1))
		{
			printf("push st1: %d\n", st1[0]);
			ft_push(st1, st2, len1, len2);
			len1--;
			len2++;
		}
		if (dist2 < dist && !ft_check_spot_order(st1, len1))
		{
			printf("push st2: %d\n", st2[0]);
			ft_push(st2, st1, len2, len1);
			len2--;
			len1++;
		}
		// len1 = dist < dist2 ? len1 - 1 : len1 + 1;
		// len2 = dist < dist2 ? len2 + 1 : len2 - 1;



		err++;
		if (err >= len)
		{
			printf("\n\nERROR: loop has no end\n");
			return (0);
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
