/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:51:00 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/23 18:23:17 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_nums(char **nums, int argc)
{
	int		numc;
	int		i;
	int		j;

	i = -1;
	numc = 0;
	while (++i < argc)
	{
		numc += ft_word_count(nums[i], ' ');
		j = -1;
		while (nums[i][++j])
			if ((!ft_isdigit(nums[i][j]) && nums[i][j] != ' ' &&
				nums[i][j] != '-') || (nums[i][j] == '-' &&
				(!ft_isdigit(nums[i][j + 1]) ||
				!(j == 0 || nums[i][j - 1] == ' '))))
				return (0);
	}
	return (numc);
}

static int	ft_nummove(char *nums, int *stack, int stack_index)
{
	int		*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_word_count(nums, ' ');
	tmp = ft_strsplit_int(nums, ' ');
	while (i < len)
	{
		stack[stack_index] = tmp[i];
		stack_index++;
		i++;
	}
	return (stack_index);
}

static int	ft_check_dup(int *buffer, int len)
{
	int		i;
	int		j;

	i = -1;
	while (++i < len && (j = -1))
		while (++j < len)
			if (buffer[i] == buffer[j] && i != j)
				return (0);
	return (1);
}

int			ft_check_input(char **nums, int **buffer, int argc)
{
	int		buff_i;
	int		numc;
	int		i;

	if (2 > (numc = ft_check_nums(nums, argc)) ||
			!(buffer[0] = (int *)ft_memalloc(sizeof(int) * numc)))
		return (0);
	i = -1;
	buff_i = 0;
	while (++i < argc)
		buff_i = ft_nummove(nums[i], buffer[0], buff_i);
	if (!(ft_check_dup(buffer[0], buff_i)))
		return (0);
	return (numc);
}
