/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:09:25 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/20 08:58:27 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * a byte for the NUL should be included in size.
 *take the full size of the buffer (not just
     the length) and guarantee to NUL-terminate the result (as long as size is
     larger than 0 or, in the case of strlcat(), as long as there is at least
     one byte free in dst).

	t_size_t	szsrclen;
	t_size_t	szcopylen;

	szsrclen = ft_strlen(src);
	if (!szsrclen)
	{
		if (size)
			dst[size -1] = '\0';
		return (szsrclen);
	}
	if (!size)
		return (szsrclen);
	szcopylen = size;
	if (szsrclen >= size)
		szcopylen--;
	ft_memmove(dst, src, szcopylen);
	dst[size - 1] = '\0';
	return (szsrclen);
 * */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	t_size_t	szsrclen;
	t_size_t	szcopylen;

	szsrclen = ft_strlen(src);
	if (!szsrclen)
	{
		dst[0] = '\0';
		return (szsrclen);
	}
	if (!size)
		return (szsrclen);
	szcopylen = size;
	if (szsrclen < szcopylen)
		szcopylen = szsrclen;
	if (szsrclen >= size)
		szcopylen--;
	ft_memmove(dst, src, szcopylen);
	dst[szcopylen] = '\0';
	return (szsrclen);
}
