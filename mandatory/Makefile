# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 21:22:19 by nlouro            #+#    #+#              #
#    Updated: 2021/12/03 15:02:56 by nlouro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

C_FLAGS = -Wall -Wextra -Werror
FT_PRINTF_DIR = ../ft_printf
FT_PRINTF_OBJ = libftprintf.a

SRV_C_FILES = server.c	ft_atoi.c	ft_isdigit.c	ft_itoa.c
CLN_C_FILES = client.c	ft_atoi.c	ft_isdigit.c	ft_itoa.c

SRV_OBJ_FILES = $(SRV_C_FILES:%.c=%.o)
CLN_OBJ_FILES = $(CLN_C_FILES:%.c=%.o)

all: $(SERVER) $(CLIENT)
s: $(SERVER)
c: $(CLIENT)

$(SERVER): $(SRV_OBJ_FILES) $(FT_PRINTF_OBJ)
	gcc $(C_FLAGS) $(SRV_OBJ_FILES) $(FT_PRINTF_DIR)/$(FT_PRINTF_OBJ) -o $(SERVER)

$(SRV_OBJ_FILES): $(C_FILES)
	gcc -c $(C_FLAGS) $(SRV_C_FILES) -I $(FT_PRINTF_DIR)

$(CLIENT): $(CLN_OBJ_FILES) $(FT_PRINTF_OBJ)
	gcc $(C_FLAGS) $(CLN_OBJ_FILES) $(FT_PRINTF_DIR)/$(FT_PRINTF_OBJ) -o $(CLIENT)

$(CLN_OBJ_FILES): $(C_FILES)
	gcc -c $(C_FLAGS) $(CLN_C_FILES) -I $(FT_PRINTF_DIR)

$(FT_PRINTF_OBJ):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(SRV_OBJ_FILES) $(CLN_OBJ_FILES)
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all
