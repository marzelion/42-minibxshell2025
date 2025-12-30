/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:38:10 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/26 10:08:50 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	if 0 length do nothing and return src size
	if 1 length do nothing but \0 = EOS is appended!!
	if dest param details unmacht do nothing and return size + lensrc
	otherwise copy and return real append len
	Boundary Condition Fix: Changed the condition from szdstlen > size 
	to szdstlen >= size. This ensures the correct behavior when 
	the dst buffer is already filled or nearly filled to the capacity.

 * */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	t_size_t	szdstlen;
	t_size_t	szsrclen;
	t_size_t	szcopylen;

	szsrclen = ft_strlen(src);
	if (!size)
		return (szsrclen);
	szdstlen = ft_strlen(dst);
	if (szdstlen > size)
		return (size + szsrclen);
	szcopylen = size - szdstlen - 1;
	if (szcopylen > szsrclen)
		szcopylen = szsrclen;
	ft_memmove(dst + szdstlen, src, szcopylen);
	dst[szdstlen + szcopylen] = '\0';
	return (szdstlen + szsrclen);
}
