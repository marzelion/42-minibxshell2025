/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:30:19 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/22 22:10:49 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*p1;
	const unsigned char		*p2;

	p1 = s1;
	p2 = s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
/*int main(void) {
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    char str3[] = "Hello, everyone!";

    int result1 = ft_memcmp(str1, str2, 13);
    printf("Comparing '%s' and '%s': %d\n", str1, str2, result1);

    int result2 = ft_memcmp(str1, str3, 13);
    printf("Comparing '%s' and '%s': %d\n", str1, str3, result2);
    
    int result3 = ft_memcmp(str1, str3, 5);
    printf("Comparing 5chars of '%s' and '%s': %d\n", str1, str3, result3);

    return 0;
}*/
