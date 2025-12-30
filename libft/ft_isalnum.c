/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:51:09 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/05 14:09:59 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *isalnum()
              checks for an alphanumeric character; it is equivalent to (isal‐
              pha(c) || isdigit(c)).

 * */
#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
