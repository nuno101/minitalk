# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 21:22:19 by nlouro            #+#    #+#              #
#    Updated: 2021/12/03 12:16:19 by nlouro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

C_FLAGS = -Wall -Wextra -Werror

SRV_C_FILES = server.c	ft_atoi.c	ft_isdigit.c	ft_itoa.c
CLN_C_FILES = client.c	ft_atoi.c	ft_isdigit.c	ft_itoa.c

SRV_OBJ_FILES = $(SRV_C_FILES:%.c=%.o)
CLN_OBJ_FILES = $(CLN_C_FILES:%.c=%.o)

all: $(SERVER) $(CLIENT)
s: $(SERVER)
c: $(CLIENT)

$(SERVER): $(SRV_OBJ_FILES)
	gcc $(C_FLAGS) $(SRV_OBJ_FILES) -o $(SERVER)

$(SRV_OBJ_FILES): $(C_FILES)
	gcc -c $(C_FLAGS) $(SRV_C_FILES)

$(CLIENT): $(CLN_OBJ_FILES)
	gcc $(C_FLAGS) $(CLN_OBJ_FILES) -o $(CLIENT)

$(CLN_OBJ_FILES): $(C_FILES)
	gcc -c $(C_FLAGS) $(CLN_C_FILES)


clean:
	rm -f $(SRV_OBJ_FILES) $(CLN_OBJ_FILES)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
