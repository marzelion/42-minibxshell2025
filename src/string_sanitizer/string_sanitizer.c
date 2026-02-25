/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_sanitizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:10:20 by marcfer3          #+#    #+#             */
/*   Updated: 2026/01/27 17:10:20 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_sanitizer.h"

int	ft_seg_len(char *rline, int *i)
{
	t_iterators	it;

	ft_init_operators(&it, i);
	while (rline[it.j])
	{
		if (rline[it.j] == '\'')
		{
			it.s_status = !it.s_status;
			it.j++;
		}
		else if (rline[it.j] == '"')
		{
			it.d_status = !it.d_status;
			it.seg_len++;
			it.j++;
		}
		else if (!ft_is_word_char(rline[it.j]) && !it.s_status && !it.d_status)
			break ;
		else
		{
			it.seg_len++;
			it.j++;
		}
	}
	return (it.seg_len);
}

char	*ft_extraer_palabra(char *rline, int *i, char *buffer, t_cmdsanit *cmd)
{
	int		j;

	j = 0;
	buffer = ft_calloc(ft_seg_len(rline, i) + 1, sizeof(char));
	if (ft_buffers_init(ft_seg_len(rline, i), cmd) == -1 || !buffer)
		return (NULL);
	while (rline[*i])
	{
		if (rline[*i] == '\'')
		{
			cmd->s_status = !cmd->s_status;
			(*i)++;
			continue ;
		}
		else if (rline[*i] == '"')
			cmd->d_status = !cmd->d_status;
		else if (!ft_is_word_char(rline[*i])
			&& !cmd->s_status && !cmd->d_status)
			break ;
		ft_add_char_shadow(cmd->s_status, cmd, j);
		buffer[j++] = rline[(*i)++];
	}
	buffer[j] = 0;
	cmd->shadow[j] = 0;
	return (buffer);
}

t_cmdsanit	**ft_sanitize_string(t_cmdsanit **cmd, char *rline)
{
	int		i;
	int		j;
	char	*buffer;

	buffer = NULL;
	j = 0;
	i = 0;
	while (rline[i] != 0 && cmd[j] != NULL)
	{
		ft_saltar_whitespace(rline, &i);
		if (ft_is_word_char(rline[i]))
		{
			buffer = ft_extraer_palabra(rline, &i, buffer, cmd[j]);
			cmd[j++]->str = buffer;
		}
	}
	return (cmd);
}

void	ft_init_cmdsanit(t_cmdsanit *cmd)
{
	cmd->s_status = 0;
	cmd->d_status = 0;
	cmd->str = NULL;
	cmd->shadow = NULL;
}

void	ft_free_cmd(t_cmdsanit **cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return ;
	while (cmd[i])
	{
		if (cmd[i]->str)
			free(cmd[i]->str);
		if (cmd[i]->shadow)
			free(cmd[i]->shadow);
		free(cmd[i]);
		cmd[i] = NULL;
		i++;
	}
}

//void	test_sanitizer(char *rline, char **expected, int expected_count)
void	test_sanitizer(char *rline)
{
	t_cmdsanit **cmd;
	int		howmanywords;
	int		i;
	//int		passed = 1;

	i = 0;
	howmanywords = ft_contar_palabras(rline);
	/*if (howmanywords != expected_count)
	{
		ft_printf("❌ FAIL | Input: \"%s\" | Expected %d words, got %d\n", rline, expected_count, howmanywords);
		return;
	}*/
	cmd = ft_calloc(howmanywords + 1, sizeof(t_cmdsanit *));
	if (!cmd)
		return;
	while (i < howmanywords)
	{
		cmd[i] = ft_calloc(1, sizeof(t_cmdsanit));
		if (!cmd[i])
		{
			ft_free_cmd(cmd);
			return ;
		}
		ft_init_cmdsanit(cmd[i]);
		i++;
	}
	cmd[i] = NULL;
	ft_sanitize_string(cmd, rline);
	ft_dqsanit(cmd);
	// Imprimir valores guardados en cmd->str y shadow
	ft_printf("   Result: ");
	i = 0;
	while (i < howmanywords)
	{
		if (cmd[i] && cmd[i]->str)
		{
			ft_printf("[%d]=\"%s\" ", i, cmd[i]->str);
			if (cmd[i]->shadow)
				ft_printf("(shadow:%s) ", cmd[i]->shadow);
		}
		else
			ft_printf("[%d]=(null) ", i);
		i++;
	}
	ft_printf("\n");
	/*
	// Verificar resultados
	i = 0;
	while (i < expected_count)
	{
		if (!cmd[i] || !cmd[i]->str || ft_strncmp(cmd[i]->str, expected[i], ft_strlen(expected[i]) + 1) != 0)
		{
			ft_printf("❌ FAIL | Input: \"%s\"\n", rline);
			ft_printf("   Word[%d]: Expected \"%s\", Got \"%s\"\n", i, expected[i], cmd[i] ? cmd[i]->str : "(null)");
			passed = 0;
		}
		i++;
	}
	
	if (passed)
		ft_printf("✓ PASS | \"%s\"\n", rline);
	*/
	// Free allocated memory
	ft_free_cmd(cmd);
	free(cmd);
}

int	mainNO_sanititzer()
{
	/*
	ft_printf("========== BASIC TESTS (NO QUOTES) ==========\n");
	test_sanitizer("hello", (char*[]){"hello"}, 1);
	test_sanitizer("echo marc fernandez", (char*[]){"echo", "marc", "fernandez"}, 3);
	test_sanitizer("  hello  world  ", (char*[]){"hello", "world"}, 2);
	test_sanitizer("   singleword   ", (char*[]){"singleword"}, 1);
	
	ft_printf("\n========== SINGLE QUOTES (FULL WORD) ==========\n");
	test_sanitizer("'hello'", (char*[]){"hello"}, 1);
	test_sanitizer("'echo marc fernandez'", (char*[]){"echo marc fernandez"}, 1);
	test_sanitizer("'hello world' test", (char*[]){"hello world", "test"}, 2);
	test_sanitizer("test 'hello world'", (char*[]){"test", "hello world"}, 2);
	
	ft_printf("\n========== DOUBLE QUOTES (FULL WORD) ==========\n");
	test_sanitizer("\"hello\"", (char*[]){"hello"}, 1);
	test_sanitizer("\"viva barxa\"", (char*[]){"viva barxa"}, 1);
	test_sanitizer("\"hello world\" test", (char*[]){"hello world", "test"}, 2);
	test_sanitizer("test \"hello world\"", (char*[]){"test", "hello world"}, 2);
	
	ft_printf("\n========== MIXED QUOTES ==========\n");
	test_sanitizer("'echo' \"viva barxa\"", (char*[]){"echo", "viva barxa"}, 2);
	test_sanitizer("\"hello\" 'world'", (char*[]){"hello", "world"}, 2);
	test_sanitizer("'single' \"double\" normal", (char*[]){"single", "double", "normal"}, 3);
	test_sanitizer("echo \"$USER\" 'no expand'", (char*[]){"echo", "$USER", "no expand"}, 3);
	
	ft_printf("\n========== SINGLE QUOTES (PARTIAL WORD) ==========\n");
	test_sanitizer("echo' marc ferna'ndez", (char*[]){"echo marc fernandez"}, 1);
	test_sanitizer("ec'ho marc' fernandez", (char*[]){"echo marc", "fernandez"}, 2);
	test_sanitizer("hel'lo wo'rld", (char*[]){"hello world"}, 1);
	
	ft_printf("\n========== DOUBLE QUOTES (PARTIAL WORD) ==========\n");
	test_sanitizer("echo\" marc ferna\"ndez", (char*[]){"echo marc fernandez"}, 1);
	test_sanitizer("ec\"ho marc\" fernandez", (char*[]){"echo marc", "fernandez"}, 2);
	test_sanitizer("hel\"lo wo\"rld", (char*[]){"hello world"}, 1);
	
	ft_printf("\n========== EDGE CASES ==========\n");
	test_sanitizer("''", (char*[]){""}, 1);
	test_sanitizer("\"\"", (char*[]){""},  1);
	test_sanitizer("'   '", (char*[]){"   "}, 1);
	test_sanitizer("\"   \"", (char*[]){"   "}, 1);
	test_sanitizer("a'   'b", (char*[]){"a   b"}, 1);
	test_sanitizer("a\"   \"b", (char*[]){"a   b"}, 1);
		ft_printf("\n========== DOUBLE QUOTES INSIDE SINGLE QUOTES (MUST KEEP \") ==========\n");
	test_sanitizer("'\"hello\"'", (char*[]){"\"hello\""}, 1);
	test_sanitizer("'echo \"test\"'", (char*[]){"echo \"test\""}, 1);
	test_sanitizer("'\"'", (char*[]){"\""}, 1);
	test_sanitizer("echo '\"viva\" barxa'", (char*[]){"echo", "\"viva\" barxa"}, 2);
	test_sanitizer("'before\"middle\"after'", (char*[]){"before\"middle\"after"}, 1);
	
	ft_printf("\n========== COMPLEX NESTED CASES ==========\n");
	test_sanitizer("\"hello\" '\"world\"'", (char*[]){"hello", "\"world\""}, 2);
	test_sanitizer("'\"test\"' \"remove\"", (char*[]){"\"test\"", "remove"}, 2);
	test_sanitizer("a\"b\"c'\"d\"'e", (char*[]){"abc\"d\"e"}, 1);
	*/
	return (0);
}
