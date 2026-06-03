#include "minishell.h"
#include <stdio.h>

int main(void)
{
    char **tokens;
    int i;

    tokens = tokenize_with_quotes("echo \"$TEST\" 'hello world' >> out");
    if (!tokens)
        return (1);
    for (i = 0; tokens[i]; i++)
        printf("[%s]\n", tokens[i]);
    free_string_array(tokens);
    return (0);
}
