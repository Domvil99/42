#include "../../C/libft/libft.h"
#include "../../C/libft/libft_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
char str[] = "Hola Mundo";
int len = ft_strlen(str);                           
 	printf("La longitud de la cadena es: %d\n", len);
 	return (0);
 }
