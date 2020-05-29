# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/08 13:46:11 by vkuikka           #+#    #+#              #
#    Updated: 2020/01/27 18:05:35 by vkuikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
EXTRAS = swap_operations.c rotate_operations.c
LIB = libft/libft.a
INCLUDE = libft/includes
.PHONY: clean fclean re all

all: $(NAME)

$(NAME):
	#make -C libft
	gcc -o $(NAME) push_swap.c $(EXTRAS) $(LIB) -I $(INCLUDE)
	gcc -o checker checker.c $(EXTRAS) $(LIB) -I $(INCLUDE)
	#gcc -o $(NAME) -Wall -Wextra -Werror $(FILES) $(LIB) -I $(INCLUDE)

clean:
	#make clean -C libft

fclean: clean
	#make fclean -C libft
	rm -f $(NAME)
	rm -f checker

re: fclean
	make all
