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

void	ft_putinfo(int len1, int len2, int *ar1, int *ar2)
{
	ft_putstr("len1: ");
	ft_putnbr(len1);
	ft_putstr("\t\tlen2: ");
	ft_putnbr(len2);
	ft_putstr("\n");
	ft_putstr("1: ");
	if (len1 > 0)
		ft_putnbr_arr(&ar1, 1, len1);
	else
		ft_putstr("empty\n");
	ft_putstr("2: ");
	if (len2 > 0)
		ft_putnbr_arr(&ar2, 1, len2);
	else
		ft_putstr("empty\n");
	ft_putstr("\n");
}

int		ft_find_closest(int num, int *stack, int len)
{
	int		res_index;
	int		smaller;
	int		bigger;
	int		i;

	i = 0;
	res_index = 0;
	bigger = 0;
	smaller = 0;
	len--;
	if (stack[i] > num)			//bigger from normal rotate
		bigger = stack[i];
	if (stack[len] > num)		//bigger from reverse rotate
	{
		bigger = stack[i];
		res_index = -1;
	}
	if (stack[i] < num)			//smaller from normal rotate
		smaller = stack[i];
	if (stack[len] < num)		//smaller from reverse rotate
	{
		smaller = stack[len - i];
		res_index = -1;
	}
	i = 1;
	while (i <= len)
	{
		if (i < len && stack[i] > num && stack[i] <= bigger)	//bigger from normal rotate
		{
			bigger = stack[i];
			if (i < ft_abs(res_index))
				res_index = i;
		}
		if (stack[len - i] > num && stack[len - i] <= bigger)	//bigger from reverse rotate
		{
			bigger = stack[i];
			if (i < ft_abs(res_index))
				res_index = i * -1;
		}
		if (i < len && stack[i] < num && stack[i] >= smaller)	//smaller from normal rotate
		{
			smaller = stack[i];
			if (i < ft_abs(res_index))
				res_index = i;
		}
		if (stack[len - i] < num && stack[len - i] >= smaller)	//smaller from reverse rotate
		{
			smaller = stack[len - i];
			if (i < ft_abs(res_index))
				res_index = i * -1;
		}
		i++;
	}
	return (res_index);
}

void	ft_swap_closest(int *st1, int *st2, int *len1, int *len2)
{
	int		distance;
	int		i;

	distance = ft_find_closest(st1[0], st2, *len2);	//find closest pushable from stack2
	ft_putstr("\nclosest = ");
	ft_putnbr(distance);
	ft_putstr("\n");
	i = 0;
	while (i < ft_abs(distance))		//rotate to found number
	{
		if (distance < 0)
			ft_rrotate(st2, *len2);
		else
			ft_rotate(st2, *len2);
		i++;
	}
	if (st2[0] >= st1[0])
	{
		ft_push(st2, st1, *len2, *len1);
		(*len2)--;
		(*len1)++;
	}
	else
	{
		ft_push(st2, st1, *len2, *len1);
		(*len2)--;
		(*len1)++;
		ft_rotate(st1, *len1);
	}
}

int		ft_check_order(int	*stack, int len)
{
	int		i;

	i = 1;
	while (i < len)
	{
		if (stack[i] < stack[i - 1])
			return(0);
		i++;
	}
	return(1);
}

int		ft_push_swap(int *st1, int *st2, int len)
{
	int		len1;
	int		len2;
	int		*correct;

	len1 = len;
	len2 = 0;

	ft_putnbr_arr(&st1, 1, len);
	ft_putstr("\n");

	if (!(correct = (int *)malloc(sizeof(int) * len)))
		return (-1);
	correct = (int *)ft_memcpy((void *)correct, (void *)st1, len);
	ft_quicksort(correct, 0, len1 - 1);

	int error = 0;
	while (!ft_check_order(st1, len))
	{
		if (error++ > 10)
			break;
		if (len1 == -1 || len2 == -1)
			exit(1);
		while (st1[0] < st1[1])		//rotate correct order
			ft_rotate(st1, len1);
		while (st1[0] > st1[1])		//push wrong order
		{
			ft_push(st1, st2, len1, len2);
			len1--;
			len2++;
			ft_rotate(st1, len1);
			ft_putinfo(len1, len2, st1, st2);
		}
		while (len2)
		{
			ft_swap_closest(st1, st2, &len1, &len2);
			ft_putinfo(len1, len2, st1, st2);
			if (!ft_check_order(st1, len1))
				while (st1[0] < st1[1])		//rotate correct order
					ft_rotate(st1, len1);
			else
			{
				ft_putstr("\nordered");
				exit(1);
			}

			ft_putinfo(len1, len2, st1, st2);
			ft_swap_closest(st1, st2, &len1, &len2);
			ft_putinfo(len1, len2, st1, st2);
		}

		ft_putstr("------------------------------------\n");
		exit(1);
	}
	// ft_putinfo(len, len1, len2, correct, st1, st2);
	// ft_putnbr_arr(&st1, 1, len1);
	ft_putnbr_arr(&correct, 1, len);
	return (1);
}

int		main(int argc, char **argv)
{
	int		*stack1;
	int		*stack2;
	int		i;

	i = -1;
	if (argc < 2)
	{
		ft_putstr("wrong amount of args\n");
		return (0);
	}
	argc--;
	if (!(stack1 = (int *)malloc(sizeof(int) * argc)) ||
		!(stack2 = (int *)malloc(sizeof(int) * argc)))
		return (0);
	while (++i < argc)
		stack1[i] = ft_atoi(argv[i + 1]);
	ft_bzero(stack2, argc);
	ft_push_swap(stack1, stack2, argc);
	return (0);
}
