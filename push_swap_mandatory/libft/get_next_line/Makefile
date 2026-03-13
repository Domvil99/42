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

SRC = get_next_line.c get_next_line_utils.c

OBJ         = $(SRC:.c=.o)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

all: $(NAME)

$(NAME): $(MAND_AR)
	@cmp -s $(MAND_AR) $(NAME) || cp $(MAND_AR) $(NAME)

$(MAND_AR): $(OBJ)
	$(RM) $(MAND_AR)
	$(AR) $(MAND_AR) $(OBJ)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(MAND_AR)

re: fclean all

.PHONY: all clean fclean re
