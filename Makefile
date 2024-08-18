# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 14:50:07 by kaokazak          #+#    #+#              #
#    Updated: 2024/08/18 15:27:56 by kaokazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

DIR_PRINTF = ft_printf
LIBFTPRINTF = libftprintf.a
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(DIR_PRINTF)/libftprintf.a :
	make -C ./$(DIR_PRINTF)

$(CLIENT) : $(DIR_PRINTF) $(SRC_CLIENT) $(DIR_PRINTF)/libftprintf.a
	$(CC) $(CFLAGS) $(SRC_CLIENT) -L./$(DIR_PRINTF)/ -lftprintf -o $(CLIENT)

$(SERVER) : $(DIR_PRINTF) $(SRC_SERVER) $(DIR_PRINTF)/libftprintf.a
	$(CC) $(CFLAGS) $(SRC_SERVER) -L./$(DIR_PRINTF)/ -lftprintf -o $(SERVER)

$(CLIENT_BONUS) : $(DIR_PRINTF) $(SRC_CLIENT_BONUS) $(DIR_PRINTF)/libftprintf.a
	$(CC) $(CFLAGS) $(SRC_CLIENT_BONUS) -L./$(DIR_PRINTF)/ -lftprintf -o $(CLIENT_BONUS)

$(SERVER_BONUS) : $(DIR_PRINTF) $(SRC_SERVER_BONUS) $(DIR_PRINTF)/libftprintf.a
	$(CC) $(CFLAGS) $(SRC_SERVER_BONUS) -L./$(DIR_PRINTF)/ -lftprintf -o $(SERVER_BONUS)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

clean:
	make fclean -C ./$(DIR_PRINTF)

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
