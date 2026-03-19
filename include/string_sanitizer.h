/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_sanitizer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 00:00:00 by marcfer3          #+#    #+#             */
/*   Updated: 2026/02/02 00:00:00 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_SANITIZER_H
# define STRING_SANITIZER_H

typedef struct s_iterators
{
	int	i;
	int	j;
	int	seg_len;
	int	s_status;
	int	d_status;
}	t_iterators;

typedef struct s_cmdsanit
{
	int		s_status;
	int		d_status;
	char	*str;
	char	*shadow;
}	t_cmdsanit;

typedef void (*t_remover)(unsigned int, char *);

t_remover	f_convert(char split);

void		void_conv(unsigned int pos, char *ps);

void		double_quotetozero(unsigned int pos, char *ps);

void		dollartozero(unsigned int pos, char *ps);

void		pipetozero(unsigned int pos, char *ps);

void		single_noexptozero(unsigned int pos, char *ps);

void		single_quotetozero(unsigned int pos, char *ps);

void		pipetoFF(unsigned int pos, char *ps);

void		FFtopipe_ws(unsigned int pos, char *ps);

#endif
