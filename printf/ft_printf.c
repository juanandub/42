/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:38:47 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/07 17:30:54 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_char(va_list a)
{
	ft_putchar_fd(va_arg(a, int), 1);
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

static int	ft_handle_hex(char o, va_list a)
{
	int				total;
	unsigned int	va;

	total = 0;
	va = va_arg(a, unsigned int);
	if (o == 'x')
		ft_putnbr_base(va, "0123456789abcdef", 16);
	else if (o == 'X')
		ft_putnbr_base(va, "0123456789ABCDEF", 16);
	if (va < 0)
		va = -va;
	else if (va == 0)
		return (1);
	while (va > 0)
	{
		total++;
		va = va / 16;
	}
	return (total);
}

static int	ft_aux(char o, va_list a)
{
	int	total;

	total = 0;
	if (o == 'c')
		total = total + ft_handle_char(a);
	else if (o == 'd' || o == 'i' || o == 'u')
		total = total + ft_handle_int(o, a);
	else if (o == 's')
		total = total + ft_handle_str(a);
	else if (o == 'x' || o == 'X')
		total = total + ft_handle_hex(o, a);
	else if (o == 'p')
		total = total + ft_handle_p(a);
	else if (o == '%')
	{
		write(1, "%%", 1);
		total = total + 1;
	}
	return (total);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start(args, format);
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
