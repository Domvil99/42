# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saospina <saospina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/05 10:31:58 by saospina          #+#    #+#              #
#    Updated: 2026/04/05 10:31:58 by saospina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

COMMON_SRCS = parse_utils.c signals_utils.c
SERVER_SRCS = server.c
CLIENT_SRCS = client.c

BONUS_SERVER_SRCS = server_bonus.c
BONUS_CLIENT_SRCS = client_bonus.c
BONUS_UTILS_SRCS = bonus_utils.c

COMMON_OBJS = $(COMMON_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
BONUS_SERVER_OBJS = $(BONUS_SERVER_SRCS:.c=.o)
BONUS_CLIENT_OBJS = $(BONUS_CLIENT_SRCS:.c=.o)
BONUS_UTILS_OBJS = $(BONUS_UTILS_SRCS:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME_SERVER): $(COMMON_OBJS) $(SERVER_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(SERVER_OBJS) $(LIBFT_A) -o $(NAME_SERVER)

$(NAME_CLIENT): $(COMMON_OBJS) $(CLIENT_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(CLIENT_OBJS) $(LIBFT_A) -o $(NAME_CLIENT)

$(NAME_SERVER_BONUS): $(COMMON_OBJS) $(BONUS_SERVER_OBJS) $(BONUS_UTILS_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(BONUS_SERVER_OBJS) $(BONUS_UTILS_OBJS) $(LIBFT_A) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(COMMON_OBJS) $(BONUS_CLIENT_OBJS) $(BONUS_UTILS_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(BONUS_CLIENT_OBJS) $(BONUS_UTILS_OBJS) $(LIBFT_A) -o $(NAME_CLIENT_BONUS)

%.o: %.c minitalk.h minitalk_bonus.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(COMMON_OBJS) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(RM) $(BONUS_SERVER_OBJS) $(BONUS_CLIENT_OBJS) $(BONUS_UTILS_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	$(RM) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
