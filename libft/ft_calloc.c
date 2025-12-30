/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:26:55 by smrtinez          #+#    #+#             */
/*   Updated: 2025/05/19 12:04:42 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * However, calloc (SIZE_MAX, SIZE_MAX) is only allowed to do one of 
 * two things: Return a pointer to an array of SIZE_MAX elements of 
 * SIZE_MAX bytes, OR return NULL. It is NOT allowed to calculate the 
 * total size by just multiplying the arguments, getting a result 
 * of 1, and allocating one byte, cleared to 0.
 *
 * 1) malloc and checks
 * 2) memset
 * 3) nmeb * size > MAX_INT  -> error?
i * 4) return block or NULL either with size=0
	TODO: bool is_aligned(void* ptr, size_t alignment) {
    return ((uintptr_t)ptr % alignment) == 0;
}
 * *) TODO: test alloc memory alignment, ensurinng that all code uses ft_calloc
...
...
    https://stackoverflow.com/questions/52699574/
	  //can-calloc-allocate-more-than-size-max-in-total...
 
If a program exceeds implementation limits, behavior is undefined

	if (!size || !nmemb || (nmemb * size) == 0)
		return ((void *)0);
 * */
#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(t_size_t nmemb, size_t size)
{
	void	*result;
	size_t	allocsize;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	allocsize = nmemb * size;
	result = malloc(allocsize);
	if (!result)
		return (NULL);
	return (ft_memset(result, 0, allocsize));
}
