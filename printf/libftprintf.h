/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:34:59 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/06 20:26:02 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *, ...);
int		ft_handle_int(char c, va_list a);
void	ft_putnbr_base(unsigned long num, char *base, int base_len);

#endif