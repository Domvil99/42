# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saospina <saospina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 17:48:19 by saospina          #+#    #+#              #
#    Updated: 2026/03/11 20:22:43 by saospina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
BONUS_MARK = .bonus
INTERNAL_DIRS = ft_printf get_next_line
INTERNAL_LIBS = ft_printf/libftprintf.a get_next_line/libftgnl.a
PACK_TMP = .pack_tmp

SRC = ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: full

mandatory: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: mandatory $(BONUS_MARK)

$(BONUS_MARK): $(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)
	@touch $(BONUS_MARK)

local_clean:
	$(RM) $(OBJ) $(BONUS_OBJ) $(BONUS_MARK)

local_fclean: local_clean
	$(RM) $(NAME) $(BONUS_MARK)

re: fclean all

internal_all:
	@for dir in $(INTERNAL_DIRS); do \
		$(MAKE) -C $$dir all || exit 1; \
	done

internal_bonus: internal_all
	@for dir in $(INTERNAL_DIRS); do \
		$(MAKE) -C $$dir bonus || exit 1; \
	done

pack_internal: mandatory internal_bonus
	@mkdir -p $(PACK_TMP)
	@for lib in $(INTERNAL_LIBS); do \
		if [ -f $$lib ]; then \
			(cd $(PACK_TMP) && ar x ../$$lib) || exit 1; \
		fi; \
	done
	@if ls $(PACK_TMP)/*.o >/dev/null 2>&1; then \
		$(AR) $(NAME) $(OBJ) $(BONUS_OBJ) $(PACK_TMP)/*.o; \
	else \
		$(AR) $(NAME) $(OBJ) $(BONUS_OBJ); \
	fi
	@$(RM) -r $(PACK_TMP)

full: mandatory bonus internal_all internal_bonus pack_internal

clean_full: local_clean
	@for dir in $(INTERNAL_DIRS); do \
		$(MAKE) -C $$dir clean || exit 1; \
	done
	@$(RM) -r $(PACK_TMP)
	@find . -type f -name '*.o' -delete

fclean_full: clean_full local_fclean
	@for dir in $(INTERNAL_DIRS); do \
		$(MAKE) -C $$dir fclean || exit 1; \
	done
	@$(RM) -r $(PACK_TMP)
	@find . -type f -name '*.a' -delete

clean: clean_full

fclean: fclean_full

.PHONY: all bonus clean fclean re internal_all internal_bonus pack_internal full clean_full fclean_full