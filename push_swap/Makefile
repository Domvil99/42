# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saospina <saospina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/13 10:10:00 by saospina          #+#    #+#              #
#    Updated: 2026/03/13 10:10:00 by saospina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

COMMON_SRC = parse.c parse_utils.c stack_build.c stack_utils.c \
	ops_swap.c ops_push.c ops_rotate.c ops_reverse_rotate.c free_utils.c

COMMON_BONUS_SRC = parse_bonus.c parse_utils_bonus.c stack_build_bonus.c \
	stack_utils_bonus.c ops_swap_bonus.c ops_push_bonus.c \
	ops_rotate_bonus.c ops_reverse_rotate_bonus.c free_utils_bonus.c

PUSH_SRC = push_swap.c sort_small.c sort_chunk.c sort_radix.c $(COMMON_SRC)
BONUS_SRC = checker_bonus.c $(COMMON_BONUS_SRC)

PUSH_OBJ = $(PUSH_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
ALL_OBJ = $(PUSH_OBJ) $(BONUS_OBJ)
LIBFT = libft/libft.a

all: $(NAME)
bonus: $(BONUS_NAME)

$(NAME): $(PUSH_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(PUSH_OBJ) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	make -C libft


push_swap.o sort_small.o sort_chunk.o sort_radix.o parse.o parse_utils.o \
	stack_build.o stack_utils.o ops_swap.o ops_push.o ops_rotate.o \
	ops_reverse_rotate.o free_utils.o: %.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

checker_bonus.o parse_bonus.o parse_utils_bonus.o stack_build_bonus.o \
	stack_utils_bonus.o ops_swap_bonus.o ops_push_bonus.o \
	ops_rotate_bonus.o ops_reverse_rotate_bonus.o \
	free_utils_bonus.o: %.o: %.c push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(ALL_OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make fclean -C libft

re: fclean all

.PHONY: all bonus clean fclean re
