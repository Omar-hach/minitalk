# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 19:39:57 by ohachami          #+#    #+#              #
#    Updated: 2023/02/07 19:51:28 by ohachami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

NAME_S = server

NAME_bonus = client_bonus

NAME_bonus_S = server_bonus

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC_bonus = minitalk_utils_b.c\

LIBFT = ./libft/libft.a

OBJ_bonus = $(SRC_bonus:.c=.o) 

all: $(NAME) $(NAME_S)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	make -C libft
	$(CC) $(CFLAGS) $(LIBFT) client.c -o $(NAME) 
	$(CC) $(CFLAGS) $(LIBFT) server.c -o $(NAME_S)

bonus: $(NAME_bonus) $(NAME_bonus_S)

$(NAME_bonus): $(OBJ_bonus)
	make -C libft
	$(CC) $(CFLAGS) $(LIBFT) client_bonus.c -o $(NAME_bonus) $(OBJ_bonus)
	$(CC) $(CFLAGS) $(LIBFT) server_bonus.c -o $(NAME_bonus_S) $(OBJ_bonus)

clean:
	make -C libft clean
	rm -f *.o libft/*.o  print/*.o

fclean: clean
	make -C libft fclean
	rm -f $(NAME) $(NAME_S) $(NAME_bonus) $(NAME_bonus_S)

re: fclean all

.PHONY: clean fclean re
