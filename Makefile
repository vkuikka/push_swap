# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/08 13:46:11 by vkuikka           #+#    #+#              #
#    Updated: 2020/08/06 16:01:36 by vkuikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
OPERATIONS = distance.c swap_operations.c rotate_operations.c stack_iteration.c input_check.c
FILES = ft_simplify.c push_swap.c
LIB = libft/libft.a
INCLUDE = libft/includes
.PHONY: clean fclean re all

all: $(NAME)

$(NAME):
	make -C libft
	gcc -o $(NAME) -Wall -Wextra -Werror $(OPERATIONS) $(LIB) $(FILES) -I $(INCLUDE)
	#gcc -o $(NAME) $(OPERATIONS) $(LIB) $(FILES) -I $(INCLUDE)
	gcc -o checker checker.c $(OPERATIONS) $(LIB) -I $(INCLUDE)

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	rm -f checker

re: fclean
	make all
