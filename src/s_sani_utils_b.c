/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sani_utils_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:06:41 by marcfer3          #+#    #+#             */
/*   Updated: 2026/02/05 11:06:41 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_sanitizer.h"
#include "libft.h"

void single_noexptozero(unsigned int pos, char *ps)
{
	(void)pos;
	if (!ps)
		return ;
	if (*ps == '\'')
		*ps = '\0';	
}

/*
 * 		//while ((pos != 0) || ((pos > 0) && (*(ps - i) != '\0')))
 * 
 * //if ((!is_indouble) || ((ps - i >= ps) && (*(ps - i) == '\0')))
 * */
void single_quotetozero(unsigned int pos, char *ps)
{
	int				is_indouble;
	unsigned int	i;
	
	is_indouble = 0;
	if (!ps)
		return ;
	if ((*ps == '\'') && (pos == 0))
		*ps = '\0';
	else if (*ps == '\'')
	{
		i = 1;
		while ((pos--) != 0)
		{
			if(*(ps - i) == '"')
				is_indouble = !is_indouble;
			if (*(ps - i) == '\0')
			{
				*ps = '\0';
				return ;
			}
			i++;
		}
		if (!is_indouble)
			*ps = '\0';
	}
}

void pipetoFF(unsigned int pos, char *ps)
{
	(void)pos;
	if (!ps)
		return ;
	if (*ps == '|')
		*ps = 0x7F;
}

void FFtopipe_ws(unsigned int pos, char *ps)
{
	(void)pos;
	if (!ps)
		return ;
	if ((*ps - 0x7F) == 0)
		*ps = '|';
	if (ft_isblank(*ps))
		*ps = ' ';
}
