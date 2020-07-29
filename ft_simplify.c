/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:28:54 by vkuikka           #+#    #+#             */
/*   Updated: 2020/07/29 17:28:57 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
// #include <stdio.h>

static int	ft_check_simplicity(int *stack, int len)
{
	int		i;
	int		current_num;
	int		new_num_found;
	int		amount;
	int 	same_num_index;

	i = 0;
	same_num_index = 0;
	amount = 0;
	current_num = 0;
	while (amount != len)
	{
		if (i == len && new_num_found && !(i = 0))
			new_num_found = 0;
		else if (i == len)
		{
			ft_putstr("NOT simplified:\t");
			ft_putnbr_arr(&stack, 1, len);
			ft_putstr("\n");
			return (0);
		}
		if (stack[i] == current_num)
		{
			// printf("index %d value %d amount %d\n", i, stack[i], amount);
			new_num_found = 1;
			same_num_index = 0;
			while (same_num_index != len)
			{
				if (stack[same_num_index] == current_num)
					amount++;
				same_num_index++;
			}
			current_num++;
		}
		i++;
	}
	ft_putstr("simplified:\t");
	ft_putnbr_arr(&stack, 1, len);
	ft_putstr("\n");
	return (1);
}

static int	ft_smallest_greater_than(int *stack, int len, int biggest_num)
{
	int		smallest;
	int		i;

	i = 0;
	smallest = 0;
	while (i < len)
	{
		if (stack[i] > biggest_num && stack[i] > stack[smallest])
			smallest = i;
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (stack[i] < stack[smallest] && stack[i] > biggest_num)
			smallest = i;
		i++;
	}
	// printf("smallest greater than %d is %d index: %d\n", biggest_num, stack[smallest], smallest);
	return (smallest);
}

static void	ft_match_equals(unsigned *simplified, int *stack, unsigned len, unsigned matchable)
{
	unsigned		i;

	i = 0;
	while (i < len)
	{
		if (stack[matchable] == stack[i])
			simplified[i] = simplified[matchable];
		i++;
	}
}

static int		ft_greatest_found(int *stack, unsigned *simplified, unsigned len)
{
	unsigned 	biggest_num_index;
	unsigned	only_zeroes;
	unsigned	i;

	i = 1;
	only_zeroes = 1;
	biggest_num_index = 0;
	while (i < len)
	{
		if (stack[i] > stack[biggest_num_index])
			biggest_num_index = i;
		if (simplified[i] != 0)
			only_zeroes = 0;
		i++;
	}
	return (simplified[biggest_num_index]);
}

unsigned int	*ft_simplify(int *stack, unsigned len)
{
	unsigned int	*simplified;
	int				simple_index;
	int				current_num;
	int				found_index;
	int				i;

	if (!(simplified = (unsigned *)malloc(sizeof(unsigned) * len)))
		return (NULL);
	i = -1;
	while(++i < len)
		simplified[i] = 0;
	current_num = 1;
	found_index = ft_find_smallest_signed(stack, len);

	i = 0;
	// ft_putnbr_arr((int **)&stack, 1, len);
	while (!ft_greatest_found(stack, simplified, len))
	{
		// ft_putnbr_arr((int **)&simplified, 1, len);
		if (i == len)
			i = 0;
		if (i == ft_smallest_greater_than(stack, len, stack[found_index]))
		{
			// printf("found %d in %d\n\n", stack[i], i);
			found_index = i;
			simplified[i] = current_num;
			ft_match_equals(simplified, stack, len, found_index);
			current_num++;
		}
		i++;
	}
	free(stack);
	return (simplified);
}

// int main(void)
// {
// 	int		*test;
// 	int		len = 10;

// 	test = (int*)malloc(sizeof(int) * len);
// 	test[0] = -9;
// 	test[1] = -2147483648;
// 	test[2] = -1;
// 	test[3] = 0;
// 	test[4] = 1;
// 	test[6] = 10;
// 	test[7] = 2147483647;
// 	test[8] = 24;
// 	test[9] = 100;
// 	ft_putstr("original:\t");
// 	ft_putnbr_arr(&test, 1, len);
// 	test = ft_simplify(test, len);
// 	ft_check_simplicity(test, len);
// 	return (0);
// }

