/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:29:15 by marcfer3          #+#    #+#             */
/*   Updated: 2025/06/09 18:11:23 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_list	*l;
	int		chars_printed;

	l = (t_list *)malloc(sizeof(t_list));
	va_start(l->ap, str);
	l->printed = 0;
	l->i = 0;
	while (str[l->i])
	{
		if (str[l->i] == '%')
		{
			if (str[++l->i] == '%')
				ft_putchar_i(str[l->i], &l->printed, &l->i);
			else
				ft_placeholders(l, str);
		}
		else
			ft_putchar_i(str[l->i], &l->printed, &l->i);
	}
	va_end(l->ap);
	chars_printed = l->printed;
	free(l);
	return (chars_printed);
}

void	ft_placeholders(t_list *l, const char *str)
{
	if (str[l->i] == 'c')
		ft_putchar_i(va_arg(l->ap, int), &l->printed, &l->i);
	else if (str[l->i] == 's')
		ft_putstr(va_arg(l->ap, char *), &l->printed, &l->i);
	else if (str[l->i] == 'd' || str[l->i] == 'i')
		ft_putnbr(va_arg(l->ap, int), &l->printed, &l->i);
	else if (str[l->i] == 'p')
		ft_putptr(va_arg(l->ap, long long unsigned), &l->printed, &l->i, 0);
	else if (str[l->i] == 'x' || str[l->i] == 'X')
		ft_puthex(va_arg(l->ap, int), &l->printed, &l->i, str[l->i]);
	else if (str[l->i] == 'u')
		ft_put_unsigned_nbr(va_arg(l->ap, unsigned int), &l->printed, &l->i);
}
