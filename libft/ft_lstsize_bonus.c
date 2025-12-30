/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:04:49 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/21 08:39:56 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	isz;

	if (!lst)
		return (0);
	isz = 0;
	while (lst != (void *)0)
	{
		lst = lst->next;
		isz++;
	}
	return (isz);
}
