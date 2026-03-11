# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saospina <saospina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 15:56:25 by saospina          #+#    #+#              #
#    Updated: 2025/10/27 18:08:13 by saospina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
MAND_AR     = .mandatory.a
BONUS_AR    = .bonus.a

SRC = ft_printf.c print_char.c print_string.c print_pointer.c \
	  print_decimal.c print_unsigned.c print_hex.c utils.c

BONUS_SRC = ft_printf_bonus.c handle_format_bonus.c parse_format_bonus.c \
            print_char_bonus.c print_str_bonus.c print_int_bonus.c \
            print_unsigned_bonus.c print_hex_bonus.c print_pointer_bonus.c

OBJ         = $(SRC:.c=.o)
BONUS_OBJ   = $(BONUS_SRC:.c=.o)

LIBFT       = ../libft.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
BONUS_CFLAGS= $(CFLAGS) -DFT_PRINTF_BONUS
AR          = ar rcs
RM          = rm -f

all: $(NAME)

$(NAME): $(MAND_AR)
	@cmp -s $(MAND_AR) $(NAME) || cp $(MAND_AR) $(NAME)

bonus: $(BONUS_AR)
	@cmp -s $(BONUS_AR) $(NAME) || cp $(BONUS_AR) $(NAME)

$(LIBFT):
	make -C ..

$(MAND_AR): $(OBJ) $(LIBFT)
	$(RM) $(MAND_AR)
	$(AR) $(MAND_AR) $(OBJ) $(LIBFT)

$(BONUS_AR): $(BONUS_OBJ) $(LIBFT)
	$(RM) $(BONUS_AR)
	$(AR) $(BONUS_AR) $(BONUS_OBJ) $(LIBFT)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ): %.o: %.c
	$(CC) $(BONUS_CFLAGS) -c $< -o $@

# Limpieza
clean:
	$(RM) *.o $(OBJ) $(BONUS_OBJ)
	make clean -C ..

fclean: clean
	$(RM) $(NAME) $(MAND_AR) $(BONUS_AR)
	make fclean -C ..

re: fclean all

.PHONY: all bonus clean fclean re