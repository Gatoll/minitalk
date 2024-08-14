# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 13:30:19 by kaokazak          #+#    #+#              #
#    Updated: 2024/04/29 17:22:19 by kaokazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT = libft.a
SRCS =  ft_printf.c \
		ft_put_cs.c \
		ft_put_di.c \
		ft_put_p.c \
		ft_put_u.c \
		ft_put_x.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJS)
	make -C ./libft
	cp ./libft/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)
	
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	make fclean -C ./libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
