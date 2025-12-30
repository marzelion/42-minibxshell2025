/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:20:15 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/15 13:34:51 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 According to all documentation
 memcpy IS FAST , BUT UNDEFINED if buffer overlaps, my implementation
 will NOT COPY THE BUFFER

 in c a custom memcpy that only copies if buffers does not 
 overlap using pointer arithmetic and no temp
	return (ft_memmove(dest, src, n));

	memcpy is faster but THE 
	check return (dest), DO NOT USE AS TRUSTED, ONLY "temporary"
	according to UNDEFINED BEHAVIOUR
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*pusrc;
	unsigned char		*pudest;

	pusrc = (const unsigned char *)src;
	pudest = (unsigned char *)dest;
	if ((dest < src && dest + n > src) || (src < dest && src + n > dest))
		return (dest);
	while (n--)
		*pudest++ = *pusrc++;
	return (dest);
}
