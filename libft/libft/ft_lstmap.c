/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:01:17 by dravaono          #+#    #+#             */
/*   Updated: 2023/04/10 15:12:22 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*first;
	t_list	*tmp;

	if (!lst)
		return (0);
	first = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!(tmp))
		{
			ft_lstclear(&first, del);
			return (0);
		}
		ft_lstadd_back(&first, tmp);
		lst = lst->next;
	}
	return (first);
}
