/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:18:42 by smrtinez          #+#    #+#             */
/*   Updated: 2025/06/23 11:47:37 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "include/ft_printf.h"
#include "include/ft_printf_convimpl.h"
#include <stdarg.h>
#include <unistd.h>

/*
 * "-0.# +0123456789[0-9]"
 *
 *
 * 	szfmt = count_conversions(fmt, valid, "cspdiuxX");
*/
t_cIMPL	*ft_getconvparam(t_cIMPL *converterimpl, va_list ap, const char *vl)
{
	const char	*t;

	t = &converterimpl->m_type;
	if (*t == vl[0])
		converterimpl->m_cval = va_arg(ap, int);
	else if (*t == vl[1])
		converterimpl->m_sval = va_arg(ap, char *);
	else if (*t == vl[2])
		converterimpl->m_pvoidval = va_arg(ap, void *);
	else if (*t == vl[3])
		converterimpl->m_idval = va_arg(ap, int);
	else if (*t == vl[4])
		converterimpl->m_idval = va_arg(ap, int);
	else if (*t == vl[5])
		converterimpl->m_uival = va_arg(ap, unsigned int);
	else
	{
		converterimpl->m_xxval = va_arg(ap, unsigned int);
		converterimpl->m_caps = 0;
		if (*t == vl[7])
			converterimpl->m_caps = 1;
	}
	return (converterimpl);
}

/*
 * 	szfmt = count_conversions(fmt, valid, "cspdiuxX");
*/
static t_converter	*ft_getconv(t_cIMPL *pimpl, va_list ap, t_pcc *vl)
{
	static t_converter		converter;
	const char				*t;

	converter.pimpl = ft_getconvparam(pimpl, ap, vl);
	t = &pimpl->m_type;
	if (*t == vl[0])
		converter.print = ft_print_c;
	else if (*t == vl[1])
		converter.print = ft_print_s;
	else if (*t == vl[2])
		converter.print = ft_print_p;
	else if (*t == vl[3])
		converter.print = ft_print_d;
	else if (*t == vl[4])
		converter.print = ft_print_d;
	else if (*t == vl[5])
		converter.print = ft_print_u;
	else
		converter.print = ft_print_xxcaps;
	return (&converter);
}

/*static ft_print_dispatch_f *print_dispatcher()
{
	static ft_print_dispatch_f ft_print_dispatch[256];

	ft_print_dispatch['c'] = ft_print_c;
	return (ft_print_dispatch);
}
*(print_dispatcher())[(int)*tokentype](fmt, &converter, &converterImpl);
			//countreslt = ft_putchar(*(fmt + 1));
		if ((pprint_dpdata->m_type == 0) || (pprint_dpdata->m_type == '%'))
*/
size_t	ft_vprintf(t_pcc *fmt, va_list ap, t_pcc *validlist)
{
	size_t		countreslt;
	t_converter	*print_dispatch;
	t_cIMPL		*pprint_dpdata;

	countreslt = 0;
	if (*(fmt + 1) == '%')
		countreslt = ft_putchar(*(fmt + 1));
	else
	{
		ft_parse(&pprint_dpdata, fmt + 1, validlist, "-0.# +123456789");
		if (pprint_dpdata->m_type == 0)
		{
			countreslt += ft_putchar('%');
		}
		else
		{
			print_dispatch = ft_getconv(pprint_dpdata, ap, validlist);
			countreslt = (*print_dispatch->print)(print_dispatch->pimpl, fmt);
		}
	}
	return (countreslt);
}

/*

			result += ft_putchar(*fmt);
*/
int	ft_printf(const char *fmt, ...)
{
	int			result;
	size_t		szfmt;
	va_list		ap;
	t_cIMPL		*p;

	result = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		szfmt = 0;
		if ((*fmt != '%') || ((*fmt == '%') && (!(*(fmt + 1)))))
			result += ft_putchar(*fmt++);
		else
		{
			szfmt = ft_vprintf(fmt, ap, "cspdiuxX");
			result += szfmt;
			szfmt = ft_parse(&p, fmt + 1, PR_TYPE, PR_FLAGS)->m_flagcount + 2;
		}
		fmt += szfmt;
	}
	va_end(ap);
	return (result);
}

int	ft_printfv(const char *fmt, va_list ap)
{
	int			result;
	size_t		szfmt;	
	t_cIMPL		*p;

	result = 0;
	while (*fmt)
	{
		szfmt = 0;
		if ((*fmt != '%') || ((*fmt == '%') && (!(*(fmt + 1)))))
			result += ft_putchar(*fmt++);
		else
		{
			szfmt = ft_vprintf(fmt, ap, "cspdiuxX");
			result += szfmt;
			szfmt = ft_parse(&p, fmt + 1, PR_TYPE, PR_FLAGS)->m_flagcount + 2;
		}
		fmt += szfmt;
	}
	return (result);
}
