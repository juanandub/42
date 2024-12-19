/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:39:45 by jpareja-          #+#    #+#             */
/*   Updated: 2024/12/11 12:32:50 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*p;
	size_t	i;
	size_t	aux;

	if (little[0] == '\0')
		return ((char *) big);
	i = 0;
	p = NULL;
	while (big[i] != '\0' && i < len)
	{
		aux = 0;
		while (big[i + aux] == little[aux] && i + aux < len)
		{
			if (little[aux + 1] == '\0')
			{
				p = (char *)&big[i];
				return (p);
			}
			aux++;
		}
		i++;
	}
	return (p);
}
