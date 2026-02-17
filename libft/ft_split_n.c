/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_n.c                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:46:23 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/15 14:44:45 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_countfilledsubstr_n(const char *s, char c, size_t n)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < n)
	{
		if (*s == c)
			count++;
		s++;
		i++;
	}
	return (count);
}

/*
 * result[i++] = ft_strdup(s);
 * */
char	**ft_split_n(char const *s, char c, size_t n)
{
	int			num_substrings;
	char		**result;
	int			i;
	size_t		j;

	num_substrings = ft_countfilledsubstr_n(s, c, n);
	result = malloc(sizeof(char *) * (num_substrings + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (j < n)
	{
		result[i++] = ft_strdup(s);
		if (!result[i - 1])
			return (ft_strsplit_release(&result));
		s += ft_strlen(result[i - 1]) + 1;
		j += ft_strlen(result[i - 1]) + 1;
	}
	result[i] = NULL;
	return (result);
}
