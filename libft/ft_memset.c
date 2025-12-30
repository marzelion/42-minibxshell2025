/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:41:14 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/14 15:28:49 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*pbegin_s;

	pbegin_s = s;
	while (n--)
		(*(unsigned char *)s++) = (unsigned char)c;
	return (pbegin_s);
}
