/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:56:38 by vkuikka           #+#    #+#             */
/*   Updated: 2020/01/27 17:57:41 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

void	ft_swap_ps(int *stack, int len);
void	ft_ss(int *stack1, int *stack2, int len1, int len2);
void	ft_push(int *stack, int *dest, int len1, int len2);
void	ft_rotate(int *stack, int len);
void	ft_rrotate(int *stack, int len);
void	ft_rr(int *stack1, int *stack2, int len1, int len2);
void	ft_rrr(int *stack1, int *stack2, int len1, int len2);

#endif