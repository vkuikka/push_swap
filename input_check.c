/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:51:00 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/06 15:53:43 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_input(char **nums, int *stack, int len)
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
		stack[i] = ft_atoi(nums[i]);
		while (j--)
		{
			if (stack[j] == stack[i])
				return (0);
		}
		i++;
	}
	return (1);
}

