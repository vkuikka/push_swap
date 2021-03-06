/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:56:38 by vkuikka           #+#    #+#             */
/*   Updated: 2020/08/23 18:49:24 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define START_FIND_DIST 5
# include "libft.h"

int			ft_swap_ps(unsigned *stack, unsigned len, char *move);
int			ft_ss(unsigned *stack1, unsigned *stack2, unsigned len1, unsigned len2);
int			ft_push(unsigned *stack, unsigned *dest, unsigned *len1, unsigned *len2);
int			ft_rotate(unsigned *stack, unsigned len, char *move);
int			ft_rrotate(unsigned *stack, unsigned len, char *move);
int			ft_rr(unsigned *stack1, unsigned *stack2, unsigned len1, unsigned len2);
int			ft_rrr(unsigned *stack1, unsigned *stack2, unsigned len1, unsigned len2);

unsigned	*ft_simplify(int *stack, unsigned len);
int			ft_find_smallest(unsigned *stack, unsigned len);
int			ft_find_smallest_signed(int *stack, unsigned len);
int			ft_find_biggest(unsigned *stack, unsigned len);
int			ft_check_order(unsigned	*stack, unsigned len);
int			ft_find_error(unsigned *stack, unsigned len);
int			ft_find_move(unsigned *st1, unsigned *st2, unsigned len1, unsigned len2);

int			ft_check_input(char **nums, int **stack, int len);
int			ft_push_dist(unsigned *st1, unsigned len1, unsigned number_to_push);

void		ft_putstack(unsigned *stack, unsigned len);

#endif
