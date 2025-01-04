/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:28:03 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/04 16:59:38 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	ft_printf("--------EMPIEZA EL TEST--------");
	ft_printf("\nELEMENTO CHAR - PRIMERO MIO LUEGO ORIGINAL\n");
	char c = 45;
	int res = ft_printf("%c ", c);
	int res1 = printf("%c ", c);
	printf("\nres: %i, res1: %i",res,res1);
	printf("\n");
	res = ft_printf("%c ", 86);
	res1 = printf("%c ", 86);
	printf("\n");
	ft_printf("res: %i, res1: %i",res,res1);
	printf("\n");
	ft_printf("\n--------------ENTEROS-----------\n");
	int i = 123;
	res = ft_printf("%d ", i);
	res1 = printf("%d ", i);
	printf("\nres: %i, res1: %i",res,res1);
	printf("\n");
	res = ft_printf("%u ", -1);
	res1 = printf("%u ", -1);
	printf("\n");
	ft_printf("res: %i, res1: %i",res,res1);
	printf("\n");
}