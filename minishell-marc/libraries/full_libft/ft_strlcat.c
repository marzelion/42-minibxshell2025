/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:37:21 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/22 22:35:30 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		dest_len;
	size_t		src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	i = 0;
	j = dest_len;
	if (dest_len < size && size > 0)
	{
		while (src[i] && j < size - 1)
		{
			dest[j] = src [i];
			j++;
			i++;
		}
		dest[j] = 0;
	}
	if (dest_len >= size)
	{
		dest_len = size;
	}
	return (dest_len + src_len);
}
/*int main(void)
{
    char dest[20] = "Hello";
    char src[] = " World!";
    size_t size = sizeof(dest);

    printf("Before ft_strlcat:\n");
    printf("Destination: %s\n", dest);
    printf("Source: %s\n", src);

    size_t result_len = ft_strlcat(dest, src, size);

    printf("\nAfter ft_strlcat:\n");
    printf("Destination: %s\n", dest);
    printf("Total length: %zu\n", result_len);

    return 0;
}
int	main()
{
	char	name1[10] = "Marc";
	char	name2[] = " Fer";
	ft_strlcat(name1, name2, 10);
	printf("tiene que salir 'marc fer': %s", name1);
	return (0);
}*/
