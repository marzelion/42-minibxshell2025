/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:13:51 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/20 11:21:12 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 *
 * Takes a node as parameter and frees its content
using the function ’del’. Free the node itself but
does NOT free the next node.
 * lst->void * = ???DEADBEEF??i
 * check next = this ?????????????
 * */
#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (!lst)
		return ;
	(*del)(lst->content);
	if (lst->next)
		lst->next = ((void *)0);
	if (lst)
	{
		free(lst);
		lst = ((void *)0);
	}
}
