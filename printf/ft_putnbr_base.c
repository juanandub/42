/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:07:31 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/07 12:22:16 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long num, char *base, int base_len)
{
	if (num >= (unsigned long)base_len)
		ft_putnbr_base(num / base_len, base, base_len);
	write(1, &base[num % base_len], 1);
}
