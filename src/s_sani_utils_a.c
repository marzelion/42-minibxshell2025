/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sani_utils_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:06:41 by marcfer3          #+#    #+#             */
/*   Updated: 2026/02/05 11:06:41 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_sanitizer.h"

void void_conv(unsigned int pos, char *ps)
{
	(void)pos;
	(void)*ps;
}

void double_quotetozero(unsigned int pos, char *ps)
{
	(void)pos;
	if (!ps)
		return ;
	if (*ps == '\"')
		*ps = '\0';
}

void dollartozero(unsigned int pos, char *ps)
{
	(void)pos;
	if (!ps)
		return ;
	if (*ps == '$')
		*ps = '\0';
}

void pipetozero(unsigned int pos, char *ps)
{
	(void)pos;
	if (!ps)
		return ;
	if (*ps == '|')
		*ps = '\0';
}

t_remover f_convert(char split)
{
	if (split == '\'')
		return (single_quotetozero);
	else if (split == '"')
		return (double_quotetozero);
	else if (split == '$')
		return (dollartozero);
	return (void_conv);
}
