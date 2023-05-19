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

SRCC = client.c

OBJC = $(SRCC:.c=.o)

SRCS = server.c

OBJS = $(SRCS:.c=.o)

SRCC_b = client_bonus.c

OBJC_b = $(SRCC_b:.c=.o)

SRCS_b = server_bonus.c

OBJS_b = $(SRCS_b:.c=.o)

SRC_bonus = minitalk_utils_b.c

OBJ_bonus = $(SRC_bonus:.c=.o) 

LIBFT = ./libft/libft.a

all: $(NAME) $(NAME_S)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJC)
	make -C libft
	$(CC) $(CFLAGS) $(LIBFT) $(OBJC) -o $(NAME)

$(NAME_S): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME_S)

bonus: $(NAME_bonus) $(NAME_bonus_S)

$(NAME_bonus): $(OBJ_bonus) $(OBJC_b)
	make -C libft
	$(CC) $(CFLAGS) $(LIBFT) $(OBJC_b) $(OBJ_bonus) -o $(NAME_bonus)

$(NAME_bonus_S): $(OBJ_bonus) $(OBJS_b)
	make -C libft
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_b) $(OBJ_bonus) -o $(NAME_bonus_S) 

clean:
	make -C libft clean
	rm -f *.o libft/*.o  print/*.o

fclean: clean
	make -C libft fclean
	rm -f $(NAME) $(NAME_S) $(NAME_bonus) $(NAME_bonus_S)

re: fclean all

.PHONY: clean fclean re
