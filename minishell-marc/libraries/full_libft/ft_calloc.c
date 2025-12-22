/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:28:30 by marcfer3          #+#    #+#             */
/*   Updated: 2025/05/23 00:14:18 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nblocks, size_t element_size)
{
	size_t	total_size;
	size_t	i;
	char	*pointer;

	if (nblocks == 0 || element_size == 0)
	{
		nblocks = 1;
		element_size = 1;
	}
	total_size = nblocks * element_size;
	if (total_size / nblocks != element_size)
		return (NULL);
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		pointer[i] = 0;
		i++;
	}
	return ((void *)pointer);
}
/*#include <stdint.h>
int main()
{
    // Test 1: Allocate an array of 5 integers (should be zeroed)
    int *arr = (int *)ft_calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);  // Expected: 0 0 0 0 0
    free(arr);

    // Test 2: Overflow check
    void *ptr = ft_calloc(SIZE_MAX, 2);  // Should return NULL
    printf("\nOverflow test: %s\n", ptr ? "FAIL" : "PASS");
}*/
