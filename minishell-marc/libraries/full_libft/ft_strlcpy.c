/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:36:17 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/22 22:53:39 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t len_dest_buffer)
{
	size_t	chars_copied;
	size_t	src_size;

	if (!dest || !src)
		return (0);
	chars_copied = 0;
	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (len_dest_buffer != 0)
	{
		while ((src[chars_copied]) && (chars_copied != len_dest_buffer - 1))
		{
			dest[chars_copied] = src[chars_copied];
			chars_copied++;
		}
		dest[chars_copied] = '\0';
	}
	return (src_size);
}
/*int	main()
{
	char name[] = "marc";
	char newname[10];

	ft_strlcpy(newname, name, 10);
	printf("newname string here: %s", newname);
	return (0);
}
int main(void)
{
    char src[] = "Hello, World!";
    char dest[20];
    size_t size = sizeof(dest);
    
    printf("Source: %s\n", src);
    size_t result = ft_strlcpy(dest, src, size);
    printf("Copied to destination: %s\n", dest);
    printf("Total length of the source string: %zu\n", result);

    return 0;
}*/
