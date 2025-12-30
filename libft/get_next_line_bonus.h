/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:33:57 by smrtinez          #+#    #+#             */
/*   Updated: 2025/07/02 16:35:21 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# define BS BUFFER_SIZE

# include <sys/types.h>

char	*get_next_line(int fd);
size_t	ft_strlen_delim(char *s, char c);
char	*ft_strncpygl(char *dest, char *src, size_t n);
char	*ft_strjoingl(char *s1, char *s2);
int		have_nl(char *s);
#endif
