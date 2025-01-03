/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:49:07 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/03 20:07:44 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_handle_int(char c, va_list a)
{
	int	total;

	total = 0;
	if (c == 'i' || c == 'd')
		total += ft_aux_int(a);
	else if (c == 'u')
	{
		/* code */
	}
	else if (c == 'x')
	{
		/* code */
	}
	else if(c == 'X')
	
	
	return (total);
}
