/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:15:51 by smrtinez          #+#    #+#             */
/*   Updated: 2025/06/23 11:06:28 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * struct ConverterImpl;
*/
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define PR_FLAGS "-0.# +123456789"
# define PR_TYPE "cspdiuxX"

typedef const char	t_pcc;
/*
 * This is the PImpl idiom! Why? Because for future complex projects
 * like minishell, would be adequate to have a resolve strategy
typedef struct s_converterIMPL
{
	char				m_type;
	int					m_cval;
	char				*m_sval;
	void				*m_pvoidval;
	int					m_idval;
	unsigned int		m_uival;
	unsigned long long	m_xxval;
	unsigned int		m_caps;
	unsigned int		m_flagcount;
	char				m_flags[10];
} t_converterIMPL,      t_cIMPL;
*/
typedef struct s_converter
{
	void			*pimpl;
	unsigned long	(*print)(void *impl, const char *);
}	t_converter;

/*
 * typedef	struct s_converter *(*defconvert)(struct s_converter *);
 * typedef unsigned long (*ft_print_dispatch_f)(void *, const char *);
 *
 * */

int		ft_printf(const char *fmt, ...);
int		ft_printfv(const char *fmt, va_list ap);
int		ft_printf2(const char *fmt, ...);

int		ft_close(int fd);
#endif
