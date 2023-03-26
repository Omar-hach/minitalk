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

NAME = rest.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC = libft/ft_atoi.c\
	libft/ft_bzero.c\
	libft/ft_calloc.c\
	libft/ft_isalnum.c\
	libft/ft_isalpha.c\
	libft/ft_isascii.c\
	libft/ft_isdigit.c\
	libft/ft_isprint.c\
	libft/ft_itoa.c\
	libft/ft_memchr.c\
	libft/ft_memcmp.c\
	libft/ft_memcpy.c\
	libft/ft_memset.c\
	libft/ft_putchar_fd.c\
	libft/ft_putendl_fd.c\
	libft/ft_putnbr_fd.c\
	libft/ft_putstr_fd.c\
	libft/ft_strchr.c\
	libft/ft_strdup.c\
	libft/ft_striteri.c\
	libft/ft_strlcat.c\
	libft/ft_strjoin.c\
	libft/ft_strlcpy.c\
	libft/ft_strlen.c\
	libft/ft_strncmp.c\
	libft/ft_strrchr.c\
	libft/ft_substr.c\
	libft/ft_split.c\
	libft/ft_memmove.c\
	libft/ft_strnstr.c\
	libft/ft_tolower.c\
	libft/ft_toupper.c\
	libft/ft_strtrim.c\
	libft/ft_strmapi.c\
	print/ft_strlen.c\
	print/ft_putnbr.c\
	print/ft_putnbr_abs.c\
	print/ft_putstr.c\
	print/ft_putchar.c\
	print/ft_printf.c\
	print/ft_address.c\

OBJ = $(SRC:.c=.o) 

OBJ_bonus = $(SRC_bonus:.c=.o) 

all: $(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CC) $(CFLAGS) -o client client.c $(NAME)
	$(CC) $(CFLAGS) -o server server.c $(NAME)

bonus: $(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CC) $(CFLAGS) -o client client_bonus.c $(NAME) minitalk_utils_b.c
	$(CC) $(CFLAGS) -o server server_bonus.c $(NAME) minitalk_utils_b.c

clean:
	rm -f *.o libft/*.o  print/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
