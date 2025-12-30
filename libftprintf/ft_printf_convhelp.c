/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convhelp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:33:43 by smrtinez          #+#    #+#             */
/*   Updated: 2025/06/23 11:58:36 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "include/ft_printf.h"
#include "include/ft_printf_convimpl.h"
#include <stdarg.h>
#include <unistd.h>

/*
	return (pval->m_flagcount + ft_atoi(pval->m_fmtlenpre));
*/
unsigned long	ft_flagcount(t_converterIMPL *pval, t_size_t putresult)
{
	unsigned long	lenpreval;

	if (!pval)
		return (putresult);
	if (!pval->m_flagcount)
		return (putresult);
	if (!pval->m_fmtlenpre)
		return (putresult + pval->m_flagcount);
	lenpreval = (unsigned long)ft_atoi_deprec(pval->m_fmtlenpre);
	if (lenpreval >= putresult)
		return (lenpreval);
	return (lenpreval);
}

unsigned long	ft_printalign(char leftminus, char f, int padding, char *str)
{
	unsigned long	result;

	if (leftminus == '-')
	{
		result = ft_putstr(str);
		while (padding-- > 0)
			result += ft_putchar(f);
		return (result);
	}
	result = 0;
	while (padding-- > 0)
		result += ft_putchar(f);
	result += ft_putstr(str);
	return (result);
}
