/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:38:47 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/03 20:19:21 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	ft_handle_char(va_list a)
{
	char	ap;

	ap = va_arg(a, int);
	write(1, &ap, 1);
	return (1);
}

static int	ft_handle_str(va_list a)
{
	char	*ap;

	ap = va_arg(a, char *);
	if (!ap)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, ap, ft_strlen(ap));
	return ((int) ft_strlen(ap));
}

static int ft_aux(char o, va_list a)
{
	int	total;

	total = 0;
	if (o == 'c')
		total = total + ft_handle_char(a) - 2;
	else if (o == 'd' || o == 'i' || o == 'u' || o == 'x' || o == 'X')
		total = total + ft_handle_int(o, a) - 2;
	else if (o == 's')
		total = total + ft_handle_str(a)- 2;
	else if (c == 'p')
	{
		
	}
	else if (o == '%')
	{
		write(1, '%', 1);
		total += 1;
	}
	return (total);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int	i;
	int total;

	i = 0;
	total = 0;
	va_start( args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total += ft_aux(format[i], args) - 2;
		}
		else
			ft_putchar_fd((const char ) format[i], 1);
		i++;
	}
	total = total + i;
	return (total);
}
