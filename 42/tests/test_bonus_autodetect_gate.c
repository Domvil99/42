#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int	path_exists(const char *path)
{
	return (access(path, F_OK) == 0);
}

int	main(int argc, char **argv)
{
	int	strict_mode;
	int	i;
	int	missing;

	if (argc < 3)
	{
		fprintf(stderr,
			"Uso: %s [--strict] <label> <ruta_bonus_1> [ruta_bonus_2 ...]\n",
			argv[0]);
		return (1);
	}
	strict_mode = 0;
	i = 1;
	if (strcmp(argv[i], "--strict") == 0)
	{
		strict_mode = 1;
		i++;
		if (argc < 4)
		{
			fprintf(stderr,
				"Uso: %s [--strict] <label> <ruta_bonus_1> [ruta_bonus_2 ...]\n",
				argv[0]);
			return (1);
		}
	}
	printf("[INFO] BONUS_CHECK label=%s\n", argv[i]);
	i++;
	missing = 0;
	while (i < argc)
	{
		if (!path_exists(argv[i]))
		{
			printf("[MISSING] %s\n", argv[i]);
			missing++;
		}
		else
			printf("[FOUND] %s\n", argv[i]);
		i++;
	}
	if (missing == 0)
	{
		printf("[OK] BONUS_AVAILABLE\n");
		return (0);
	}
	printf("[SKIP] BONUS_NOT_AVAILABLE (%d rutas faltantes)\n", missing);
	if (strict_mode)
		return (2);
	return (0);
}
