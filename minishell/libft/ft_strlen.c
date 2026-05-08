/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:15:27 by saospina           #+#    #+#            */
/*   Updated: 2025/05/18 17:15:30 by saospina          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char *end = s;

	while(*end)
		end++;
	return(end - s);
}
/*
int main(void)
{
char str[] = "Hola Mundo";
int len = ft_strlen(str);                           
 	printf("La longitud de la cadena es: %d\n", len);
 	return (0);
 }
*/
