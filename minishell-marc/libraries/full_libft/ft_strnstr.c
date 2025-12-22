/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:22:59 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/22 23:30:21 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

char	*ft_strnstr( const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen((char *)s2);
	if (!len)
	{
		return ((char *)s1);
	}
	while (*s1 && len <= n--)
	{
		if (!ft_memcmp(s1, s2, len))
			return ((char *)s1);
		s1++;
	}
	return (0);
}
/*int main(void) {
    char haystack[] = "Hello, World!";
    char needle[] = "World";
    size_t max_len = 12;

    char *result = ft_strnstr(haystack, needle, max_len);
    if (result) {
        printf("Found '%s' in '%s': '%s'\n", needle, haystack, result);
    } else {
        printf("'%s' not found in '%s'\
        first %zu characters\n", needle, haystack, max_len);
    }

    char needle2[] = "Universe";
    result = ft_strnstr(haystack, needle2, max_len);
    if (result) {
        printf("Found '%s' in '%s': '%s'\n", needle2, haystack, result);
    } else {
        printf("'%s' not found in '%s' \
        swithin the first %zu characters\n", needle2, haystack, max_len);
    }

    char needle3[] = "";
    result = ft_strnstr(haystack, needle3, max_len);
    if (result) {
        printf("Found empty needle in '%s': '%s'\n", haystack, result);
    } else {
        printf("Empty needle not found in '%s'\n", haystack);
    }

    return 0;
}
int	main()
{
	char	stack[] = "mi nombre es marc fernandez cruz";
	char	needle[] = "marc";
	char	*p = ft_strnstr(stack, needle, strlen(stack));
	printf("Buscando la substring '%s' en el stack: %s", needle, p);
}*/
