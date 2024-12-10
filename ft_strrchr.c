/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:02:40 by jpareja-          #+#    #+#             */
/*   Updated: 2024/12/06 14:12:41 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strrchr(const char *string, int c)
{
	int i;

	i = ft_strlen(string);
	while (i >= 0)
	{
		if (string[i] == c)
			return ((char*)&string[i]);
		i--;
	}
	return (0);
}
