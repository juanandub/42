/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:07:31 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/06 20:22:01 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_base(unsigned long num, char *base, int base_len)
{
	if(num >= (unsigned long) base_len)
		ft_putnbr_base(num / base_len, base, base_len);
	write(1, &base[num % base_len], 1);
}
