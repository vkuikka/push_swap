/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:28:20 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/06 15:32:52 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	ft_swap_operations(int **stacks, int *lengths, char *instruction)
{
	int		ret;

	ret = -1;
	if (!ft_strcmp(instruction, "sa"))
		ret = ft_swap_ps((unsigned *)stacks[0], lengths[0]);
	else if (!ft_strcmp(instruction, "sb"))
		ret = ft_swap_ps((unsigned *)stacks[1], lengths[1]);
	else if (!ft_strcmp(instruction, "ss"))
		ret = ft_ss((unsigned *)stacks[0], (unsigned *)stacks[1],
				lengths[0], lengths[1]);
	else if (!ft_strcmp(instruction, "pb"))
	{
		ret = ft_push((unsigned *)stacks[0], (unsigned *)stacks[1],
				lengths[0], lengths[1]);
		lengths[0]--;
		lengths[1]++;
	}
	else if (!ft_strcmp(instruction, "pa"))
	{
		ret = ft_push((unsigned *)stacks[1], (unsigned *)stacks[0],
				lengths[1], lengths[0]);
		lengths[1]--;
		lengths[0]++;
	}
	return (ret);
}

static int	ft_rotate_operations(int **stacks, int *lengths, char *instruction)
{
	int		ret;

	ret = -1;
	if (!ft_strcmp(instruction, "ra"))
		ret = ft_rotate((unsigned *)stacks[0], lengths[0]);
	else if (!ft_strcmp(instruction, "rb"))
		ret = ft_rotate((unsigned *)stacks[1], lengths[1]);
	else if (!ft_strcmp(instruction, "rr"))
		ret = ft_rr((unsigned *)stacks[0], (unsigned *)stacks[1],
				lengths[0], lengths[1]);
	else if (!ft_strcmp(instruction, "rra"))
		ret = ft_rrotate((unsigned *)stacks[0], lengths[0]);
	else if (!ft_strcmp(instruction, "rrb"))
		ret = ft_rrotate((unsigned *)stacks[1], lengths[1]);
	else if (!ft_strcmp(instruction, "rrr"))
		ret = ft_rrr((unsigned *)stacks[0], (unsigned *)stacks[1],
				lengths[0], lengths[1]);
	return (ret);
}

static int	ft_evaluate(int **stacks, int *lengths)
{
	char	*instruction;
	int		tmp;
	int		tmp2;

	ft_putnbr_arr(&stacks[0], 1, lengths[0]);
	ft_putnbr_arr(&stacks[1], 1, lengths[1]);
	while (0 < (tmp = get_next_line(0, &instruction)))
	{
		if (0 >= (tmp = ft_rotate_operations(stacks, lengths, instruction)) &&
			0 >= (tmp2 = ft_swap_operations(stacks, lengths, instruction)))
			return (tmp > tmp2 ? tmp : tmp2);
		ft_putnbr_arr(&stacks[0], 1, lengths[0]);
		ft_putnbr_arr(&stacks[1], 1, lengths[1]);
	}
	if (tmp < 0)
		return (-1);
	if (lengths[1])
		return (0);
	while (tmp < lengths[0] - 1)
	{
		if (stacks[0][tmp] > stacks[0][tmp + 1])
			return (0);
		tmp++;
	}
	return (1);
}

static int	ft_check_input(char **nums, int **stacks, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(nums[i], ft_itoa(ft_atoi(nums[i]))))
			return (0);
		j = 0;
		while (nums[i][j])
		{
			if ((nums[i][j] > '9' || nums[i][j] < '0') && nums[i][j] != '-')
				return (0);
			j++;
		}
		j = i;
		stacks[0][i] = ft_atoi(nums[i]);
		while (j--)
		{
			if (stacks[0][j] == stacks[0][i])
				return (0);
		}
		i++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		**stacks;
	int		lengths[2];
	int		tmp;

	if (argc == 1 ||
		(!(stacks = (int **)malloc(sizeof(int*) * 2))) ||
		(!(stacks[0] = (int *)malloc(sizeof(int) * argc - 1))) ||
		(!(stacks[1] = (int *)malloc(sizeof(int) * argc - 1))))
		return (1);
	if (!ft_check_input(argv + 1, stacks, argc - 1))
	{
		ft_putstr("Error\n");
		return (1);
	}
	lengths[0] = argc - 1;
	lengths[1] = 0;
	if (0 < (tmp = ft_evaluate(stacks, lengths)))
		ft_putstr("OK\n");
	else if (tmp < 0)
		ft_putstr("Error\n");
	else
		ft_putstr("KO\n");
	return (0);
}
