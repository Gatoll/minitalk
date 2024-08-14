NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF = libftprintf.a
CLIENT = client.c
SERVER = server.c

all: $(NAME)

$(NAME): ft_printf
	make -C ./ft_printf
	cp ./ft_printf/$(PRINTF) ./
	$(CC) $(CFLAGS) $(CLIENT) -L./ -lftprintf -o client
	$(CC) $(CFLAGS) $(SERVER) -L./ -lftprintf -o server

clean:
	make fclean -C ./ft_printf
	rm -f $(PRINTF)

fclean: clean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re 
