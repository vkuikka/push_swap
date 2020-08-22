/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:28:54 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/19 12:56:47 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// static int		ft_check_simplicity(int *stack, int len)
// {
// 	int		i;
// 	int		current_num;
// 	int		new_num_found;
// 	int		amount;
// 	int 	same_num_index;

// 	i = -1;
// 	same_num_index = 0;
// 	amount = 0;
// 	current_num = 0;
// 	while (amount != len)
// 	{
// 		if (i == len && new_num_found && !(i = 0))
// 			new_num_found = 0;
// 		else if (i == len)
// 		{
// 			ft_putstr("not simplified\n");
// 			return (0);
// 		}
// 		else if (stack[i] == current_num)
// 		{
// 			new_num_found = 1;
// 			same_num_index = 0;
// 			while (same_num_index != len)
// 				if (stack[same_num_index++] == current_num)
// 					amount++;
// 			current_num++;
// 		}
// 		i++;
// 	}
// 	ft_putstr("simplified:\t");
// 	ft_putnbr_arr(&stack, 1, len);
// 	ft_putstr("\n");
// 	return (1);
// }

static int		ft_smallest_greater_than(int *stack, int len, int biggest_num)
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
	return (smallest);
}

static void		ft_match_equals(unsigned *simplified, int *stack, unsigned len, unsigned matchable)
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
	int				current_num;
	int				found_index;
	int				i;

	i = -1;
	current_num = 1;
	found_index = ft_find_smallest_signed(stack, len);
	if (!(simplified = (unsigned *)malloc(sizeof(unsigned) * len)))
		return (NULL);
	while (++i < len)
		simplified[i] = 0;
	i = 0;
	while (!ft_greatest_found(stack, simplified, len))
	{
		if (i == ft_smallest_greater_than(stack, len, stack[found_index]))
		{
			found_index = i;
			simplified[i] = current_num++;
			ft_match_equals(simplified, stack, len, found_index);
		}
		i = i == len - 1 ? 0 : i + 1;
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

