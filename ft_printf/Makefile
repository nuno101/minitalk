# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouro <nlouro@student.42heilbronn.de>       +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 23:47:18 by nlouro              #+#    #+#            #
#    Updated: 2021/10/08 14:08:20 by nlouro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_FLAGS =  -c -Wall -Wextra -Werror

C_FILES = ft_printf.c	ft_printf_utils.c

OBJ_FILES = $(C_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

$(OBJ_FILES): $(C_FILES)
	gcc $(C_FLAGS) $(C_FILES)

clean:
	rm -f $(OBJ_FILES) 

fclean: clean
	rm -f $(OBJ_FILES) 
	rm -f $(NAME)

re: fclean all
