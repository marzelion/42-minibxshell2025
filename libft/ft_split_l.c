/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_l.c                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:46:23 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/15 14:44:45 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_splititeri(char **a, void (*f)(unsigned int, char **))
{
	unsigned int	i;

	i = 0;
	while (a)
	{
		(*f)(i, &a[i]);
		a++;
		i++;
	}
}
int	ft_countufsubstr(const char *s, char c, size_t n)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < n)
	{
		while ((i < n) && (*s != c))
		{
			s++;
			i++;
		}
		count++;
		if (i < n)
		{
			count++;
			s++;
			i++;
		}
	}
	return (count);
}
/*
int	ft_countfilledsubstr_l(const char *s, char c, size_t n)
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
*/
/*
 * result[i++] = ft_strdup(s);
 * c contains and EXTRA character to be joined or
 * //strlen will fail
 	//	c[0] = (char)0xFF;* 
 * */
char	**ft_split_l(char const *s, char c[2], size_t n)
{
	int			num_substrings;
	char		**result;
	int			i;
	size_t		j;

	num_substrings = ft_countufsubstr(s, '\0', n);
	result = malloc(sizeof(char *) * (num_substrings + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	c[1] = '\0';
	while (j < n)
	{
		result[i++] = FT_JOIN(s, c);
		if (!result[i - 1])
			return (ft_strsplit_release(&result));
		result[i - 1][ft_strlen(result[i - 1]) - 1] = '\0';
		if ((ft_strlen(result[i - 1]) > 0) || !(s++ && j++))
			s += ft_strlen(result[i - 1]);
		j += ft_strlen(result[i - 1]);
	}
	c[1] = (char)j;
	result[i] = NULL;
	return (result);
}
