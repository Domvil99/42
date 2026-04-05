# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saospina <saospina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/13 20:41:17 by saospina          #+#    #+#              #
#    Updated: 2026/03/13 21:05:36 by saospina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = push_swap.c parse.c parse_utils.c stack_build.c stack_utils.c \
	ops_swap.c ops_push.c ops_rotate.c ops_reverse_rotate.c free_utils.c \
	sort_small.c sort_chunk.c sort_radix.c

OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
