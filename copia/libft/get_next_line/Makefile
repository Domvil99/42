# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saospina <saospina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/12 00:00:00 by saospina          #+#    #+#              #
#    Updated: 2026/03/12 00:00:00 by saospina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftgnl.a
MAND_AR     = .mandatory.a
BONUS_AR    = .bonus.a

SRC = get_next_line.c get_next_line_utils.c

BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ         = $(SRC:.c=.o)
BONUS_OBJ   = $(BONUS_SRC:.c=.o)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

all: $(NAME)

$(NAME): $(MAND_AR)
	@cmp -s $(MAND_AR) $(NAME) || cp $(MAND_AR) $(NAME)

bonus: $(BONUS_AR)
	@cmp -s $(BONUS_AR) $(NAME) || cp $(BONUS_AR) $(NAME)

$(MAND_AR): $(OBJ)
	$(RM) $(MAND_AR)
	$(AR) $(MAND_AR) $(OBJ)

$(BONUS_AR): $(OBJ) $(BONUS_OBJ)
	$(RM) $(BONUS_AR)
	$(AR) $(BONUS_AR) $(OBJ) $(BONUS_OBJ)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME) $(MAND_AR) $(BONUS_AR)

re: fclean all

.PHONY: all bonus clean fclean re
