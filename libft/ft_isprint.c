/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:43:33 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/06 12:44:06 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	checks for any printable character including space.
 *	he c argument is an int, the value of which the application shall  en‐
       sure  is  a character representable as an unsigned char or equal to the
       value of the macro EOF.
 * */
#include "libft.h"

int	ft_isprint(int c)
{
	return ((c >= 040) && (c <= 0176));
}
