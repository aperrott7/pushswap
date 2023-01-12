/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:37:55 by amaso             #+#    #+#             */
/*   Updated: 2022/01/28 15:38:16 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*prev;

	if (!lst)
		return ;
	list = *lst;
	while (list)
	{
		del(list->content);
		prev = list;
		list = list->next;
		free(prev);
	}
	*lst = NULL;
}
