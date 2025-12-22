/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:58:53 by marcfer3          #+#    #+#             */
/*   Updated: 2025/06/09 17:42:29 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *str, size_t *printed, size_t *i)
{
	size_t	e;
	size_t	j;
	char	*nll;

	nll = "(null)";
	j = 0;
	e = 0;
	if (str == NULL)
	{
		while (nll[j] != '\0')
		{
			ft_putchar(nll[j], printed);
			j++;
		}
		(*i)++;
		return ;
	}
	while (str[e])
	{
		ft_putchar(str[e], printed);
		e++;
	}
	(*i)++;
}
