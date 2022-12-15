/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:23:00 by amaso             #+#    #+#             */
/*   Updated: 2022/01/28 18:23:41 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list_funct;
	t_list	*node;

	if (!lst)
		return (NULL);
	list_funct = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
			ft_lstclear(&node, del);
		else
			ft_lstadd_back(&list_funct, node);
		lst = lst->next;
	}
	return (list_funct);
}
