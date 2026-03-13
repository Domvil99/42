# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saospina <saospina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/09 16:23:41 by saospina          #+#    #+#              #
#    Updated: 2026/03/11 18:37:29 by saospina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
MAND_AR     = .mandatory.a

SRC = ft_printf.c print_char.c print_string.c print_pointer.c \
	  print_decimal.c print_unsigned.c print_hex.c utils.c

OBJ         = $(SRC:.c=.o)

LIBFT       = ../libft.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

all: $(NAME)

$(NAME): $(MAND_AR)
	@cmp -s $(MAND_AR) $(NAME) || cp $(MAND_AR) $(NAME)

$(LIBFT):
	make -C ..

$(MAND_AR): $(OBJ) $(LIBFT)
	$(RM) $(MAND_AR)
	$(AR) $(MAND_AR) $(OBJ) $(LIBFT)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
	$(RM) *.o $(OBJ)
	make clean -C ..

fclean: clean
	$(RM) $(NAME) $(MAND_AR)
	make fclean -C ..

re: fclean all

.PHONY: all clean fclean re
