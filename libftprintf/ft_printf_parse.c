/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:42:31 by smrtinez          #+#    #+#             */
/*   Updated: 2025/06/23 11:11:29 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "include/ft_printf.h"
#include "include/ft_printf_convimpl.h"
#include <stdarg.h>

static t_cIMPL	*cimplfactory(void)
{
	static t_cIMPL	converterimpl;

	converterimpl.lasttoken = (void *)0;
	converterimpl.m_flagcount = 0;
	converterimpl.m_type = 0;
	ft_memset(converterimpl.m_flags, 0, 6);
	converterimpl.m_fmtlenpre = (void *)0;
	return (&converterimpl);
}

/*
 * 0) Handle incorrect cases %.....% or %..... %
 * 1) correct % [cspdiuxX]
 *
 *  nexttoken = strchr(fmt, "%") 
 *  strchr( "%", nexttoken) < nexttoken
 *
 * types = "cpsudixX" *
 * flags = "-0.# +"
			//atoi(fmt + pconverter->m_flagcount ??!!!!!!!)??
 * */
t_cIMPL	*ft_parse(t_cIMPL **p, const char *fmt, t_pcc *types, t_pcc *flags)
{
	*p = cimplfactory();
	while (*fmt)
	{
		if (ft_strchr(types, *fmt))
		{
			(*p)->m_type = *(ft_strchr(types, *fmt));
			break ;
		}
		(*p)->lasttoken = ft_strchr(flags, *fmt);
		if ((*p)->lasttoken)
		{
			if (ft_isdigit(*(*p)->lasttoken) && (!(*p)->m_fmtlenpre))
				(*p)->m_fmtlenpre = fmt;
			else
				(*p)->m_flags[(*p)->lasttoken - flags] = *(*p)->lasttoken;
			(*p)->m_flagcount++;
		}
		else
		{
			(*p)->m_flagcount = 0;
			break ;
		}
		fmt++;
	}
	return (*p);
}
