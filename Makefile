# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 21:22:19 by nlouro            #+#    #+#              #
#    Updated: 2021/11/17 21:43:22 by nlouro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

C_FLAGS = -Wall -Wextra -Werror

C_FILES = server.c

OBJ_FILES = $(C_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	gcc $(C_FLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_FILES): $(C_FILES)
	gcc -c $(C_FLAGS) $(C_FILES)

clean:
	rm -f $(OBJ_FILES) 

fclean: clean
	rm -f $(OBJ_FILES) 
	rm -f $(NAME)

re: fclean all
