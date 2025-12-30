/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:59:55 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/17 11:34:52 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
 *TODO: safer version using ??
	result = ft_calloc((len+1), sizeof(char));
	
	if (!s)
		return ((void *)0);
 * */
char	*ft_strdup(const char *s)
{
	char		*result;
	t_size_t	buflen;

	buflen = ft_strlen(s) + 1;
	result = (char *) malloc(buflen);
	if (!result)
		return ((void *)0);
	ft_memset(result, 0, buflen);
	buflen = ft_strlcpy(result, s, buflen);
	return (result);
}
