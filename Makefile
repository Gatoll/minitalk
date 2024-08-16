NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF = libftprintf.a
CLIENT = client.c
SERVER = server.c
CLIENT_BONUS = client_bonus.c
SERVER_BONUS = server_bonus.c

all: $(NAME)

$(NAME): ft_printf
	make -C ./ft_printf
	cp ./ft_printf/$(PRINTF) ./
	$(CC) $(CFLAGS) $(CLIENT) -L./ -lftprintf -o client
	$(CC) $(CFLAGS) $(SERVER) -L./ -lftprintf -o server

bonus: $(NAME)
	touch bonus
	$(CC) $(CFLAGS) $(CLIENT_BONUS) -L./ -lftprintf -o client_bonus
	$(CC) $(CFLAGS) $(SERVER_BONUS) -L./ -lftprintf -o server_bonus

clean:
	make fclean -C ./ft_printf
	rm -f $(PRINTF)

fclean: clean
	rm -f client server client_bonus server_bonus bonus

re: fclean all

.PHONY: all clean fclean re 
