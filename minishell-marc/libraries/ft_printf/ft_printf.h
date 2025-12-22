/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:26:55 by marcfer3          #+#    #+#             */
/*   Updated: 2025/06/11 00:10:47 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct list
{
	size_t	printed;
	size_t	i;
	va_list	ap;
}	t_list;

int		ft_printf(const char *str, ...);
void	ft_placeholders(t_list *l, const char *str);
void	ft_putchar(char c, size_t *printed);
void	ft_putstr(const char *str, size_t *printed, size_t *i);
void	ft_putptr(long long unsigned n, size_t *printed, size_t *i, int flag);
void	ft_puthex(unsigned int n, size_t *printed, size_t *i, char c);
void	ft_put_unsigned_nbr(unsigned int n, size_t *printed, size_t *i);
void	ft_putnbr(long long n, size_t *printed, size_t *i);
void	ft_putchar_i(char c, size_t *printed, size_t *index);
#endif
