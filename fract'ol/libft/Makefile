# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saospina <saospina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 17:48:19 by saospina          #+#    #+#              #
#    Updated: 2026/04/14 22:23:00 by saospina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
BONUS_MARK = .bonus

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
INTERNAL_DIRS = ft_printf get_next_line
PACK_TMP = .pack_tmp

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(NAME) $(BONUS_MARK)

$(BONUS_MARK): $(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)
	@touch $(BONUS_MARK)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ) $(BONUS_MARK)

fclean: clean
	$(RM) $(NAME) $(BONUS_MARK)

re: fclean all

internal_all:
	@for d in $(INTERNAL_DIRS); do \
		if [ -d "$$d" ]; then \
			$(MAKE) -C $$d all; \
		fi; \
	done

internal_bonus:
	@for d in $(INTERNAL_DIRS); do \
		if [ -d "$$d" ]; then \
			$(MAKE) -C $$d bonus; \
		fi; \
	done

pack_internal:
	@mkdir -p $(PACK_TMP)
	@$(RM) $(PACK_TMP)/*.o
	@$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)
	@if [ -f ft_printf/libftprintf.a ]; then \
		cd $(PACK_TMP) && ar -x ../ft_printf/libftprintf.a; \
	fi
	@if [ -f get_next_line/libftgnl.a ]; then \
		cd $(PACK_TMP) && ar -x ../get_next_line/libftgnl.a; \
	fi
	@if ls $(PACK_TMP)/*.o >/dev/null 2>&1; then \
		$(AR) $(NAME) $(PACK_TMP)/*.o; \
	fi
	@$(RM) -r $(PACK_TMP)

full: all bonus internal_all internal_bonus pack_internal

internal_clean:
	@for d in $(INTERNAL_DIRS); do \
		if [ -d "$$d" ]; then \
			$(MAKE) -C $$d clean; \
		fi; \
	done

internal_fclean:
	@for d in $(INTERNAL_DIRS); do \
		if [ -d "$$d" ]; then \
			$(MAKE) -C $$d fclean; \
		fi; \
	done

clean_full: clean internal_clean
	@$(RM) -r $(PACK_TMP)
	@for d in $(INTERNAL_DIRS); do \
		if [ -d "$$d" ]; then \
			find $$d -type f -name '*.o' -delete; \
		fi; \
	done

fclean_full: fclean internal_fclean
	@$(RM) -r $(PACK_TMP)
	@for d in $(INTERNAL_DIRS); do \
		if [ -d "$$d" ]; then \
			find $$d -type f -name '*.a' -delete; \
		fi; \
	done

.PHONY: all bonus clean fclean re internal_all internal_bonus pack_internal \
	full internal_clean internal_fclean clean_full fclean_full