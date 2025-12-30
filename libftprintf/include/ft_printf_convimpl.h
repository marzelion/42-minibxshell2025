/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convimpl.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:38:00 by smrtinez          #+#    #+#             */
/*   Updated: 2025/06/23 11:07:28 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_CONVIMPL_H
# define FT_PRINTF_CONVIMPL_H

typedef const char	t_pcc;

/*
	m_flags is a bolean array: "-0.# +"
*/
typedef struct s_converterIMPL
{
	const char			*lasttoken;
	char				m_type;
	int					m_cval;
	char				*m_sval;
	void				*m_pvoidval;
	int					m_idval;
	unsigned int		m_uival;
	unsigned long long	m_xxval;
	unsigned int		m_caps;
	unsigned int		m_flagcount;
	unsigned int		m_flags[6];
	const char			*m_fmtlenpre;
} t_converterIMPL,	t_cIMPL;

unsigned long	ft_flagcount(t_converterIMPL *pval, t_size_t putresult);
t_cIMPL			*ft_parse(t_cIMPL **p, const char *fmt, t_pcc *ts, t_pcc *flag);
unsigned long	ft_printalign(char leftminus, char f, int padding, char *str);
unsigned long	ft_print_c(void *impl, const char *fmt);
unsigned long	ft_print_s(void *impl, const char *fmt);
unsigned long	ft_print_p(void *impl, const char *fmt);
unsigned long	ft_print_d(void *impl, const char *fmt);
unsigned long	ft_print_u(void *impl, const char *fmt);
unsigned long	ft_print_xxcaps(void *impl, const char *fmt);

#endif
