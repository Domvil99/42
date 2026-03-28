CC := cc
CFLAGS := -Wall -Wextra -Werror

FT_PRINTF_DIR := ../../C/ft_printf
FT_PRINTF_A := $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_A := $(FT_PRINTF_DIR)/libft/libft.a
INCLUDES := -I$(FT_PRINTF_DIR)

MAND_TEST := test_mandatory_matrix
BONUS_TEST := test_bonus_matrix

.PHONY: all mandatory bonus clean fclean re

all: mandatory bonus

mandatory:
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(MAND_TEST).c $(FT_PRINTF_A) $(LIBFT_A) -o $(MAND_TEST)

bonus:
	$(MAKE) -C $(FT_PRINTF_DIR) bonus
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_TEST).c $(FT_PRINTF_A) $(LIBFT_A) -o $(BONUS_TEST)

clean:
	rm -f $(MAND_TEST) $(BONUS_TEST)

fclean: clean
	@true

re: fclean all
