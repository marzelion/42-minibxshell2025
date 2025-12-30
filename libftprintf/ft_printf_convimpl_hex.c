/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convimpl_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:41:48 by smrtinez          #+#    #+#             */
/*   Updated: 2025/06/23 12:17:02 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "include/ft_printf.h"
#include "include/ft_printf_convimpl.h"
#include <stdarg.h>
#include <unistd.h>

unsigned long	ft_print_xxcaps(void *impl, const char *fmt)
{
	t_converterIMPL		*pval;
	unsigned long long	ullval;

	pval = ((t_converterIMPL *)(impl));
	(void)fmt;
	ullval = (unsigned long long)pval->m_xxval;
	if (pval->m_caps == 0)
		return (ft_flagcount(pval, ft_puthex(ullval, 16, "0123456789abcdef")));
	return (ft_flagcount(pval, ft_puthex(ullval, 16, "0123456789ABCDEF")));
}

unsigned long	ft_print_p(void *impl, const char *fmt)
{
	size_t				count;
	t_converterIMPL		*pval;

	pval = ((t_converterIMPL *)(impl));
	(void)fmt;
	if (!pval->m_pvoidval)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	pval->m_caps = 0;
	pval->m_xxval = (unsigned long)pval->m_pvoidval;
	count += ft_print_xxcaps(impl, fmt);
	return (ft_flagcount(pval, count));
}
