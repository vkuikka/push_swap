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

void	ft_swap_ps(unsigned *stack, unsigned len);
void	ft_ss(unsigned *stack1, unsigned *stack2, unsigned len1, unsigned len2);
void	ft_push(unsigned *stack, unsigned *dest, unsigned len1, unsigned len2);
void	ft_rotate(unsigned *stack, unsigned len);
void	ft_rrotate(unsigned *stack, unsigned len);
void	ft_rr(unsigned *stack1, unsigned *stack2, unsigned len1, unsigned len2);
void	ft_rrr(unsigned *stack1, unsigned *stack2, unsigned len1, unsigned len2);
int		*ft_simplify(int *stack, int len);

#endif
