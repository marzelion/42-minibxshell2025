/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:04:20 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/21 08:37:27 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * if new->next is not NULL, do not add
 * */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if ((!new) || (!lst))
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = (*lst);
	*lst = new;
}
