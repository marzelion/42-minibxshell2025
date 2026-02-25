/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_counting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:36:58 by marcfer3          #+#    #+#             */
/*   Updated: 2026/01/28 10:36:58 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_sanitizer.h"

int	ft_is_word_char(int c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\f' || c == '\r')
		return (0);
	return (1);
}

void	ft_saltar_whitespace(char *rline, int *i)
{
	while (rline[*i] && !ft_is_word_char(rline[*i]))
		(*i)++;
	return ;
}

void	ft_iterar_palabra(char *rline, int *i)
{
	int	status;
	int	status_doble;

	status = 0;
	status_doble = 0;
	while (rline[*i])
	{
		if (rline[*i] == '\'')
			status = !status;
		else if (rline[*i] == '"')
			status_doble = !status_doble;
		else if (!ft_is_word_char(rline[*i])
			&& (status == 1 || status_doble == 1))
		{
			(*i)++;
			continue ;
		}
		else if (!ft_is_word_char(rline[*i]) && (!status && !status_doble))
			return ;
		(*i)++;
	}
	return ;
}

int	ft_contar_palabras(char *rline)
{
	int	palabras;
	int	i;

	palabras = 0;
	i = 0;
	while (rline[i])
	{
		if (!ft_is_word_char(rline[i]))
			ft_saltar_whitespace(rline, &i);
		else if (ft_is_word_char(rline[i]))
		{
			palabras++;
			ft_iterar_palabra(rline, &i);
		}
	}
	return (palabras);
}

/*int	main()
{
	//gpt tests
	printf("========== BASIC TESTS (NO QUOTES) ==========\n");
	printf("Expected: 0 | Got: %d | \"%s\"\n", ft_contar_palabras(""), "");
	printf("Expected: 1 | Got: %d | \"%s\"\n", ft_contar_palabras("hello"), "hello");
	printf("Expected: 3 | Got: %d | \"%s\"\n", ft_contar_palabras("echo marc fernandez"), "echo marc fernandez");
	printf("Expected: 2 | Got: %d | \"%s\"\n", ft_contar_palabras("  hello  world  "), "  hello  world  ");
	printf("Expected: 1 | Got: %d | \"%s\"\n", ft_contar_palabras("   singleword   "), "   singleword   ");
	
	printf("\n========== SINGLE QUOTES (FULL WORD) ==========\n");
	printf("Expected: 1 | Got: %d | \"%s\"\n", ft_contar_palabras("'hello'"), "'hello'");
	printf("Expected: 1 | Got: %d | \"%s\"\n", ft_contar_palabras("'echo marc fernandez'"), "'echo marc fernandez'");
	printf("Expected: 2 | Got: %d | \"%s\"\n", ft_contar_palabras("'hello world' test"), "'hello world' test");
	printf("Expected: 2 | Got: %d | \"%s\"\n", ft_contar_palabras("test 'hello world'"), "test 'hello world'");
	
	printf("\n========== SINGLE QUOTES (PARTIAL WORD) ==========\n");
	printf("Expected: 1 | Got: %d | \"%s\"\n", ft_contar_palabras("echo' marc ferna'ndez"), "echo' marc ferna'ndez");
	printf("Expected: 2 | Got: %d | \"%s\"\n", ft_contar_palabras("ec'ho marc' fernandez"), "ec'ho marc' fernandez");
	printf("Expected: 2 | Got: %d | \"%s\"\n", ft_contar_palabras("'echo marc' fernandez"), "'echo marc' fernandez");
	printf("Expected: 1 | Got: %d | \"%s\"\n", ft_contar_palabras("hel'lo wo'rld"), "hel'lo wo'rld");
	
	printf("\n========== MULTIPLE QUOTES ==========\n");
	printf("Expected: 2 | Got: %d | \"%s\"\n", ft_contar_palabras("ec'ho marc' ferna''ndez"), "ec'ho marc' ferna''ndez");
	printf("Expected: 1 | Got: %d | \"%s\"\n", ft_contar_palabras("'a''b''c'"), "'a''b''c'");
	printf("Expected: 3 | Got: %d | \"%s\"\n", ft_contar_palabras("'a' 'b' 'c'"), "'a' 'b' 'c'");
	
	printf("\n========== EDGE CASES ==========\n");
	printf("Expected: 0 | Got: %d | \"%s\"\n", ft_contar_palabras("   "), "   ");
	printf("Expected: 0 | Got: %d | \"%s\"\n", ft_contar_palabras("''"), "''");
	printf("Expected: 1 | Got: %d | \"%s\"\n", ft_contar_palabras("'   '"), "'   '");
	printf("Expected: 2 | Got: %d | \"%s\"\n", ft_contar_palabras("a'   'b"), "a'   'b");
	printf("Expected: 1 | Got: %d | \"%s\"\n", ft_contar_palabras("word'"), "word'");
	printf("Expected: 1 | Got: %d | \"%s\"\n", ft_contar_palabras("'word"), "'word");
}*/