/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:07:02 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/21 10:07:26 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * //DO NOT !!lst = &(tmp->next);
 * */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	if (!*lst)
		return ;
	while ((*lst))
	{
		tmp = *lst;
		*lst = (tmp->next);
		ft_lstdelone(tmp, del);
	}
}
