#include "libft.h"
#include <stdlib.h>

static size_t	ft_word_count(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_word_dup(const char *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

static void	ft_free_split(char **words, size_t i)
{
	while (i > 0)
		free(words[--i]);
	free(words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	words = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!words)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			words[i] = ft_word_dup(s, c);
			if (!words[i++])
				return (ft_free_split(words, i - 1), NULL);
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	words[i] = NULL;
	return (words);
}
/*
int	main(void)
{
	char	**result;
	char	str[] = "Hola, mundo! Bienvenido a la programacion.";
	size_t	i;

	result = ft_split(str, ' ');
	if (!result)
		return (1);
	i = 0;
	while (result[i])
	{
		printf("Palabra %zu: %s\n", i, result[i]);
		i++;
	}
	ft_free_split(result, i);
	return (0);
}
*/
