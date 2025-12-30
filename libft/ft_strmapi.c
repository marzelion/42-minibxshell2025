/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:35:40 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/10 17:35:43 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	t_size_t		len;
	unsigned int	i;

	if (!s || !f)
		return ((void *)0);
	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (!result)
		return ((void *)0);
	i = 0;
	while (i < len)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}
