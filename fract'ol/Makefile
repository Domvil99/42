NAME = fractol
BONUS_NAME = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

INCLUDES = -I. -I$(LIBFT_DIR) -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRCS = main.c init.c parse_args.c fractal_calc.c render.c events.c utils.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = main_bonus.c init_bonus.c parse_args_bonus.c fractal_calc_bonus.c \
	render_bonus.c events_bonus.c utils_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) full

$(MLX):
	if [ -f $(MLX_DIR)/configure ]; then chmod +x $(MLX_DIR)/configure; fi
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(BONUS_NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean_full
	find $(LIBFT_DIR) -type f -name '*.o' -delete
	if [ -f $(MLX_DIR)/configure ]; then chmod +x $(MLX_DIR)/configure; fi
	if [ -f $(MLX_DIR)/makefile.gen ]; then $(MAKE) -C $(MLX_DIR) clean; fi

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean_full
	find $(LIBFT_DIR) -type f -name '*.a' -delete

re: fclean all

.PHONY: all bonus clean fclean re
