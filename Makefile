# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/08 13:46:11 by vkuikka           #+#    #+#              #
#    Updated: 2020/07/29 17:42:14 by vkuikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
OPERATIONS = distance.c swap_operations.c rotate_operations.c
EXTRAS = ft_simplify.c stack_iteration.c
LIB = libft/libft.a
INCLUDE = libft/includes
.PHONY: clean fclean re all

all: $(NAME)

$(NAME):
	#make -C libft
	gcc -o $(NAME) push_swap.c $(OPERATIONS) $(LIB) $(EXTRAS) -I $(INCLUDE)
	#gcc -o checker checker.c $(OPERATIONS) $(LIB) -I $(INCLUDE)
	#gcc -o $(NAME) -Wall -Wextra -Werror $(OPERATIONS) $(LIB) $(EXTRAS) -I $(INCLUDE)

clean:
	#make clean -C libft

fclean: clean
	#make fclean -C libft
	rm -f $(NAME)
	rm -f checker

re: fclean
	make all
