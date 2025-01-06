/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:40:20 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/06 20:44:08 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_handle_p(va_list a)
{
	int				total;
	unsigned long	va;

	total = 2;
	va = (unsigned long)va_arg(a, void *);
	write(1, "0x", 2);
	ft_putnbr_base(va, "0123456789abcdef", 16);
	while (va > 0)
	{
		total++;
		va = va / 16;
	}
	return (total);
}
