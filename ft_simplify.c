#include "libft.h"
#include <stdio.h>

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

static int	ft_find_smallest(int *stack, int len)
{
	int		smallest;
	int		i;

	i = 1;
	smallest = 0;
	while (i < len)
	{
		// printf("smallest: %d, index: %d\n", smallest, i);
		if (stack[i] < stack[smallest])
			smallest = i;
		i++;
	}
	return (smallest);
}

static void	ft_match_equals(int *simplified, int *stack, int len, int matchable)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (stack[matchable] == stack[i])
			simplified[i] = simplified[matchable];
		i++;
	}
}

int			ft_greatest_found(int *stack, int *simplified, int len)
{
	int 	biggest_num_index;
	int		only_zeroes;
	int		i;

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

int			*ft_simplify(int *stack, int len)
{
	unsigned int	*simplified;
	int				simple_index;
	int				current_num;
	int				found_index;
	int				i;

	if (!(simplified = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	ft_bzero(simplified, len);
	current_num = 1;
	found_index = ft_find_smallest(stack, len);

	int j = 0;
	i = 0;
	// ft_putnbr_arr((int **)&stack, 1, len);
	while (!ft_greatest_found(stack, simplified, len))
	{
		j++;
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
	return (simplified);
}

int main(void)
{
	int		*test;
	int		len = 10;
	int		*og;

	test = (int*)malloc(sizeof(int) * len);
	og = test;
	test[0] = -9;
	test[1] = -5;
	test[2] = -1;
	test[3] = 0;
	test[4] = 1;
	test[6] = 10;
	test[7] = 15;
	test[8] = 24;
	test[9] = 100;
	test = ft_simplify(test, len);
	ft_check_simplicity(test, len);
	ft_putstr("original:\t");
	ft_putnbr_arr(&og, 1, len);
	return (0);
}