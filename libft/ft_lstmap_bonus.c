/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:53:25 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/21 10:55:39 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*pfrontnew;
	t_list	*new;

	if (!lst || !f)
		return ((void *)0);
	pfrontnew = (void *)0;
	while (lst != (void *)0)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&pfrontnew, del);
			return (pfrontnew);
		}
		ft_lstadd_back(&pfrontnew, new);
		lst = lst->next;
	}
	return (pfrontnew);
}
