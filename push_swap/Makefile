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
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_CORE = parse.c parse_utils.c stack_build.c stack_utils.c \
	ops_swap.c ops_push.c ops_rotate.c ops_reverse_rotate.c free_utils.c

SRC_MAND = push_swap.c sort_small.c sort_chunk.c sort_radix.c
SRC_BONUS = checker_bonus.c checker_exec_bonus.c checker_read_bonus.c

OBJ_CORE = $(SRC_CORE:.c=.o)
OBJ_MAND = $(SRC_MAND:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ_CORE) $(OBJ_MAND) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CORE) $(OBJ_MAND) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(OBJ_CORE) $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CORE) $(OBJ_BONUS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	make -C libft

%.o: %.c push_swap.h checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_CORE) $(OBJ_MAND) $(OBJ_BONUS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make fclean -C libft

re: fclean all

.PHONY: all bonus clean fclean re
