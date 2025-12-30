/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:43:18 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/21 09:20:22 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * if new->next is not NULL, do not add
 * */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pback;

	if ((!new) || (!lst))
		return ;
	if (!*lst)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	pback = ft_lstlast(*lst);
	if (pback == *lst)
	{
		ft_lstadd_front(&pback->next, new);
		return ;
	}
	ft_lstadd_front(&pback->next, new);
}
