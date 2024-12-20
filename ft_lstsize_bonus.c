/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:21:06 by jpareja-          #+#    #+#             */
/*   Updated: 2024/12/20 16:43:36 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		result;
	t_list	*current;

	result = 0;
	current = lst;
	while (current != NULL)
	{
		result++;
		current = current->next;
	}
	return (result);
}
