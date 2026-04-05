#include "libft.h"
#include "libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	assert_int(const char *name, int got, int expected)
{
	if (got != expected)
	{
		fprintf(stderr, "[FAIL] %s: got=%d expected=%d\n", name, got, expected);
		return (1);
	}
	return (0);
}

int	main(void)
{
	char	*dup;
	char	*join;

	if (assert_int("ft_strlen", (int)ft_strlen("hola"), 4) != 0)
		return (1);
	if (assert_int("ft_isdigit", ft_isdigit('7'), 1) != 0)
		return (1);
	if (assert_int("ft_toupper", ft_toupper('a'), 'A') != 0)
		return (1);
	dup = ft_strdup("abc");
	if (!dup || strcmp(dup, "abc") != 0)
		return (fprintf(stderr, "[FAIL] ft_strdup\n"), free(dup), 1);
	join = ft_strjoin("ab", "cd");
	if (!join || strcmp(join, "abcd") != 0)
		return (fprintf(stderr, "[FAIL] ft_strjoin\n"), free(dup), free(join), 1);
	free(dup);
	free(join);
	printf("[OK] libft portable strict\n");
	return (0);
}
