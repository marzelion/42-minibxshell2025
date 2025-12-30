/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarrayutils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:46:47 by smrtinez          #+#    #+#             */
/*   Updated: 2025/08/07 14:46:49 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

/* #include "number_conv.h"
 * */
/*
 * search if val is already in the number list
 * numlen might be the size of array or less
 * */

int	ft_check_repeated(int val, int **assign, size_t numlen)
{
	size_t	i;

	if (!assign)
		return (0);
	if (!*assign)
		return (0);
	if (numlen < 1)
		return (1);
	i = 0;
	while (i < numlen)
	{
		if (val == (*assign)[i])
			return (0);
		if (i == (numlen - 1))
			return (1);
		i++;
	}
	return (1);
}

size_t	ft_safe_retrelease(size_t ret, int **assign)
{
	if (!assign)
		return (ret);
	if (!*assign)
		return (ret);
	free(*assign);
	*assign = NULL;
	return (ret);
}

/*
 * watchout zero case and one-length
 * */
size_t	ft_parsetoints(size_t argc, char **argv, int **assign)
{
	size_t		cnt;
	int			*result;

	cnt = 0;
	if ((argc < 1) || (!argv) || (!assign))
		return (0);
	result = (int *) malloc((argc) * sizeof(int));
	*assign = result;
	if (!result)
		return (0);
	while (cnt < argc)
	{
		if (ft_strlen(argv[cnt]) == 0)
			return (ft_safe_retrelease(0, assign));
		result[cnt] = 0;
		if (ft_atoi_val(argv[cnt], &result[cnt]) == -1)
			return (ft_safe_retrelease(0, assign));
		if (!ft_check_repeated(result[cnt], &result, cnt))
			return (ft_safe_retrelease(0, assign));
		cnt++;
	}
	return (cnt);
}
