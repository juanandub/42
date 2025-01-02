/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:38:47 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/02 18:01:27 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int ft_aux(char c, va_list a)
{
	if (c == 'c')
	{
		char ap = va_arg(a, int);
		write(1, &ap, 1);
		return (1);
	}
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int	i;
	int total;

	i = 0;
	va_start( args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total = total + ft_aux(format[i], args) - 2;
		}else{
			ft_putchar_fd((const char ) format[i], 1);
		}
		i++;
	}
	total = total + i;
	return (total);
}
