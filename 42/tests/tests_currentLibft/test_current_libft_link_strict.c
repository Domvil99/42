#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	const char	*msg = "currentLibft";
	int			ret;

	if (ft_strlen(msg) != 12)
	{
		fprintf(stderr, "[FAIL] ft_strlen inesperado\n");
		return (1);
	}
	ret = ft_printf("[OK] %s integration alive\n", msg);
	if (ret <= 0)
	{
		fprintf(stderr, "[FAIL] ft_printf retorno invalido\n");
		return (1);
	}
	return (0);
}
