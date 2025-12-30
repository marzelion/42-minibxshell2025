/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:28:33 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/15 13:32:30 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *The  memcpy()  function  copies  n bytes from memory area src to memory
       area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
       memory areas do overlap
       "as though" means not mandatory temp buffer!
 * *  stackOverf suggestion implementation
 * equestionanswers[dot]com/c/memcpy-vs-memmove.php
 * memmove is VERY SLOW but the safer one!!!!
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*pusrc;
	unsigned char		*pudest;

	pusrc = (const unsigned char *)src;
	pudest = (unsigned char *)dest;
	if ((pusrc < pudest) && ((pusrc + n) > pudest))
	{
		pusrc += n;
		pudest += n;
		while (n-- > 0)
		{
			*--pudest = *--pusrc;
		}
	}
	else
	{
		while (n--)
		{
			*pudest++ = *pusrc++;
		}
	}
	return (dest);
}
