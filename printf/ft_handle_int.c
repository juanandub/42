/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:49:07 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/04 17:05:07 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_aux_int(va_list a)
{
	int	total;
	int	va;

	total = 0;
	va = va_arg(a, int);
	ft_putnbr_fd(va , 1);
	while (va > 0)
	{
		total++;
		va = va / 10;
	}
	return (total);
}

static int	ft_aux_uint(va_list a)
{
	int				total;
	unsigned int	va;

	total = 0;
	va = va_arg(a, unsigned int);
	ft_putnbr_base(va , "0123456789", 10);
	while (va > 0)
	{
		total++;
		va = va / 10;
	}
	return (total);
}

int	ft_handle_int(char c, va_list a)
{
	int	total;

	total = 0;
	if (c == 'i' || c == 'd')
		total = total + ft_aux_int(a);
	else if(c == 'u')
		total = total + ft_aux_uint(a);
	return (total);
}
