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

# include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

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

/* struct_counting.c */
int		ft_is_word_char(int c);
void	ft_saltar_whitespace(char *rline, int *i);
void	ft_iterar_palabra(char *rline, int *i);
int		ft_contar_palabras(char *rline);

/* string_sanitizer.c */
int		ft_seg_len(char *rline, int *i);
int		ft_buffers_init(int size, t_cmdsanit *cmd);
char	*ft_extraer_palabra(char *rline, int *i, char *buffer, t_cmdsanit *cmd);
t_cmdsanit	**ft_sanitize_string(t_cmdsanit **cmd, char *rline);
void	ft_init_cmdsanit(t_cmdsanit *cmd);
void	ft_free_cmd(t_cmdsanit **cmd);
void	ft_add_char_shadow(int status, t_cmdsanit *cmd, int position);

/* double_q.c */
char	*ft_look_for_quotes(t_cmdsanit *cmd);
int		ft_no_dq_string_len(t_cmdsanit *cmd);
int		ft_dqsanit(t_cmdsanit **cmd);
void	ft_init_operators(t_iterators *it, int *i);

#endif
