#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	ft_putnbr_fd(12345, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(-12345, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);
	return (0);
}
