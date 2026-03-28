NAME := tests_libft
CC := cc
CFLAGS := -Wall -Wextra -Werror
LIBFT_DIR := ../../C/libft
LIBFT_A := $(LIBFT_DIR)/libft.a
INCLUDES := -I$(LIBFT_DIR)

SRCS := $(wildcard test_*.c)
BINS := $(SRCS:.c=)

.PHONY: all bonus run clean fclean re list

all: $(LIBFT_A) $(BINS)

# Build libft with bonus too, so tests for ft_lst* can link successfully.
bonus:
	$(MAKE) -C $(LIBFT_DIR) bonus
	$(MAKE) all

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

%: %.c $(LIBFT_A)
	$(CC) $(CFLAGS) $(INCLUDES) $< $(LIBFT_A) -o $@

run: all
	@for bin in $(BINS); do \
		echo "==> ./$$bin"; \
		./$$bin || exit $$?; \
	done

list:
	@printf '%s\n' $(BINS)

clean:
	rm -f $(BINS)

fclean: clean
	@true

re: fclean all
