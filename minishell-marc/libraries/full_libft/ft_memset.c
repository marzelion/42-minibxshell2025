/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:09 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/22 22:29:37 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	unsigned char	c;
	size_t			i;

	i = 0;
	p = ptr;
	c = value;
	if (!ptr)
		return (NULL);
	while (i < num)
	{
		p[i] = c;
		i++;
	}
	return (p);
}
/*#include <string.h>
int main(void)
{
    char str[50] = "Hello, World! This is a test string."; 
    char str_ft[50];
    char str_std[50];
    
    strcpy(str_ft, str);
    strcpy(str_std, str);

    printf("Original string: %s\n", str);

    ft_memset(str_ft, '3', 6);
    printf("After ft_memset: %s\n", str_ft);

    memset(str_std, '*', 6);
    printf("After standard memset: %s\n", str_std);

    return 0;
}
int	main()
{
	char	array[4] = "Marc";
	printf("%s", array);
	ft_memset(array, 67, 2);
	printf("%s", array);
}*/
