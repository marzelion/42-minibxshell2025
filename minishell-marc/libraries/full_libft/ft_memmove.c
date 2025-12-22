/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:38:20 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/22 22:22:52 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include  <stdio.h>
//#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d < s)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d = d + (n - 1);
		s = s + (n - 1);
		while (n--)
		{
			*d-- = *s--;
		}
	}
	return (dest);
}
/*int main(void)
{
    char src[] = "Hello, World!";
    char dst[50];
    
    printf("Before ft_memmove:\n");
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dst);

    ft_memmove(dst, src, strlen(src) + 1);
    
    printf("\nAfter ft_memmove:\n");
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dst);

    return 0;
}
int	main()
{
	char	name[] = "marc";
	ft_memmove(name, name + 2, 4);
	printf("This should be rcrc: %s\n", name); 
	return (0);
}*/
