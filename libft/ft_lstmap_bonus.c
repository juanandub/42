/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:01:39 by jpareja-          #+#    #+#             */
/*   Updated: 2024/12/27 13:54:37 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*nodex;
	t_list	*aux;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	aux = new;
	lst = lst->next;
	while (lst)
	{
		nodex = ft_lstnew(f(lst->content));
		if (!nodex)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		aux->next = nodex;
		aux = nodex;
		lst = lst->next;
	}
	return (new);
}
