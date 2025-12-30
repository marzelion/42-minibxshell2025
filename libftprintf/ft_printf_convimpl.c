/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convimpl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:40:36 by smrtinez          #+#    #+#             */
/*   Updated: 2025/06/23 11:45:35 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "include/ft_printf.h"
#include "include/ft_printf_convimpl.h"
#include <stdarg.h>
#include <unistd.h>

unsigned long	ft_print_c(void *impl, const char *fmt)
{
	t_converterIMPL	*pval;

	pval = ((t_converterIMPL *)(impl));
	(void)fmt;
	return (ft_flagcount(pval, ft_putchar((char)pval->m_cval)));
}

unsigned long	ft_print_s(void *impl, const char *fmt)
{
	t_converterIMPL	*pval;
	int				padding;
	char			fillchar;

	fillchar = ' ';
	padding = 0;
	pval = ((t_converterIMPL *)(impl));
	(void)fmt;
	if (!pval->m_sval)
		return (ft_putstr("(null)"));
	if (pval->m_fmtlenpre)
		padding = ft_atoi_deprec(pval->m_fmtlenpre);
	if (!padding && !ft_strlen(pval->m_sval))
		return (0);
	if (pval->m_flags[1])
		fillchar = '0';
	padding -= ft_strlen(pval->m_sval);
	return (ft_printalign(pval->m_flags[0], fillchar, padding, pval->m_sval));
}

unsigned long	ft_print_d(void *impl, const char *fmt)
{
	t_converterIMPL	*pval;

	pval = ((t_converterIMPL *)(impl));
	(void)fmt;
	return (ft_flagcount(pval, ft_putnbr(pval->m_idval)));
}

unsigned long	ft_print_u(void *impl, const char *fmt)
{
	t_converterIMPL	*pval;

	pval = ((t_converterIMPL *)(impl));
	(void)fmt;
	return (ft_flagcount(pval, ft_puthex(pval->m_uival, 10, "0123456789")));
}
