/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:45:43 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/08 15:45:56 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Allocates memory (using malloc(3)) and returns a
copy of ’s1’ with characters from ’set’ removed
from the beginning and the end.
 Identify the characters to be trimmed from the beginning 
 and the end of the string.
    Use a custom ft_substr function to create a new string 
    that excludes the trimmed characters.
    Allocate memory for the new string and return it.

 * */
/*char *ft_strtrim(char const *s1, char const *set)
{
	const char	*ps1end;
	const char	*ptrimbegin;
	t_size_t	len;
	const char	*pset;

	if (!s1)
		return ((void *)0);
	if (!set)
		return (ft_strdup(s1));
	ptrimbegin = s1;
	ps1end = s1 + ft_strlen(s1);
	pset = set;
	while (*pset){
		while ((*ptrimbegin == *pset) && (ptrimbegin != ps1end))
		{
		printf("beginn test %c\n",*pset);
			ptrimbegin++;
			pset = set;
			continue;
		}
		pset++;
	}
	pset = set;
	while(*pset)
		prrintf("end test %c-%c\n",*pset,*ps1end);
		while ((*ps1end == *pset) && (ps1end != ptrimbegin))
		{
		printf("end testfo %c\n",*pset);
			ps1end--;
			pset = set;
			continue;
		}
		pset++;
	}
	len = ps1end - ptrimbegin;
	return (ft_substr(ptrimbegin,0, len));
}
*/
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*ps1end;
	const char	*ptrimbegin;
	t_size_t	len;

	if (!s1)
		return ((void *)0);
	if (!set)
		return (ft_strdup(s1));
	ptrimbegin = s1;
	ps1end = s1 + ft_strlen(s1);
	while (*ptrimbegin && ft_strchr(set, *ptrimbegin))
		ptrimbegin++;
	while (ps1end > ptrimbegin && ft_strchr(set, *(ps1end - 1)))
		ps1end--;
	len = ps1end - ptrimbegin;
	return (ft_substr(ptrimbegin, 0, len));
}
