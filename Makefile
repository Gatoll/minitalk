# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 14:50:07 by kaokazak          #+#    #+#              #
#    Updated: 2024/08/20 00:19:20 by kaokazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

DIR_LIBFT = libft
LIBFT = libft.a
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

$(DIR_LIBFT)/libft.a :
	make -C ./$(DIR_LIBFT)

$(CLIENT) : $(DIR_LIBFT) $(SRC_CLIENT) $(DIR_LIBFT)/libft.a
	$(CC) $(CFLAGS) $(SRC_CLIENT) -L./$(DIR_LIBFT)/ -lft -o $(CLIENT)

$(SERVER) : $(DIR_LIBFT) $(SRC_SERVER) $(DIR_LIBFT)/libft.a
	$(CC) $(CFLAGS) $(SRC_SERVER) -L./$(DIR_LIBFT)/ -lft -o $(SERVER)

$(CLIENT_BONUS) : $(DIR_LIBFT) $(SRC_CLIENT_BONUS) $(DIR_LIBFT)/libft.a
	$(CC) $(CFLAGS) $(SRC_CLIENT_BONUS) -L./$(DIR_LIBFT)/ -lft -o $(CLIENT_BONUS)

$(SERVER_BONUS) : $(DIR_LIBFT) $(SRC_SERVER_BONUS) $(DIR_LIBFT)/libft.a
	$(CC) $(CFLAGS) $(SRC_SERVER_BONUS) -L./$(DIR_LIBFT)/ -lft -o $(SERVER_BONUS)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

clean:
	make fclean -C ./$(DIR_LIBFT)

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
