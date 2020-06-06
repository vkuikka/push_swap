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
			ft_putstr("not simplified yet: ");
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
	ft_putstr("simplified: ");
	ft_putnbr_arr(&stack, 1, len);
	ft_putstr("\n");
	return (1);
}


// int main(void)
// {
// 	int *test;

// 	test = (int*)malloc(sizeof(int) * 7);
// 	test[0] = 0;
// 	test[1] = 2;
// 	test[2] = 1;
// 	test[3] = 4;
// 	test[4] = 2;
// 	test[5] = 3;
// 	test[6] = 9;
// 	ft_check_simplicity(test, 7);
// 	return (0);
// }

static int	ft_is_smallest_greater_than(int *stack, int len, int index, int biggest_num)
{
	int		smallest;

	return (index == smallest);
}

void		ft_simplify(int *stack, int len)
{
	unsigned int	*simplified;
	int				simple_index;
	int				current_num;
	int				found_index;
	int				i;

	if (!(simplified = (int *)malloc(sizeof(int) * len)))
		return (0);
	ft_bzero(simplified, len);
	current_num = 0;
	found_index = ft_find_smallest(stack, len);

	while (1)
	{
		if (ft_is_smallest_greater_than(stack, len, i, stack[found_index]))
		{
			found_index = i;
			simplified[simple_index] = current_num;
		}
	}

}
