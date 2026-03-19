/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:10:26 by marvin            #+#    #+#             */
/*   Updated: 2026/02/26 18:10:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf/include/ft_printf.h"
#include "minishellx.h"
#include <stdlib.h>
#include <readline/readline.h>
#include <limits.h>

typedef struct s_mirror
{
	char    *str;
	char    *mirror;
}  	t_mirror;

typedef struct s_iterators
{
	int	c_simple;
	int	c_doble;
	int	i;
	int	j;
}	t_iter;

void	ft_free_and_replace(t_mirror *cmd, t_mirror *buffer)
{
	if (cmd->str)
		free(cmd->str);
	if (cmd->mirror)
		free(cmd->mirror);
	cmd->str = buffer->str;
	cmd->mirror = buffer->mirror;
	return ;
}

void	ft_look_byte(t_iter *it, char *mirror, char *line)
{
	if (line[it->i] == ' ' && (it->c_simple || it->c_doble))
	{
		mirror[it->i] = '2';
		it->i++;
	}
	if (line[it->i] && it->c_simple)
		mirror[it->i] = '0';
	else
		mirror[it->i] = '1';
	it->i++;
	return ;
}

char	*ft_create_mirror(char *line)
{
	t_iter	it;
	char	*mirror;

	ft_bzero(&it, sizeof(t_iter));
	mirror = ft_calloc(1, ft_strlen(line));
	if (!mirror)
		return (NULL);
	while (line[it.i])
	{
		if (line[it.i] == '\'')
		{
			it.c_simple = !it.c_simple;
			mirror[it.i] = '0';
			it.i++;
			continue;
		}
		else if (line[it.i] == '"')
		{
			it.c_doble = !it.c_doble;
			mirror[it.i] = '0';
			it.i++;
			continue;
		}
		ft_look_byte(&it, mirror, line);		
	}
	return (mirror);
}

int	ft_sq_sanit(t_mirror *cmd)
{
	/**
	 * sobreescribir también el shadow
	 * Si '1' -> interpretar
	 * si '0' -> no interpretar
	 */
	t_iter	val;
	t_mirror	buffer;

	ft_bzero(&val, sizeof(val));
	buffer.str = ft_calloc(sizeof(ft_strlen(cmd->str)) + 1, 1);
	buffer.mirror = ft_calloc(sizeof(ft_strlen(cmd->mirror)) + 1, 1);
	if (!buffer.str || !buffer.mirror)
		return (-1);
	while (cmd->str[val.i])
	{
		if (cmd->str[val.i] == '\'')
		{
			val.i++;
			continue ;
		}
		buffer.str[val.j] = cmd->str[val.i];
		buffer.mirror[val.j++] = cmd->mirror[val.i++];
	}
	buffer.str[val.j] = '\0';
	buffer.mirror[val.j] = '\0';
	ft_free_and_replace(cmd, &buffer);
	return (0);
}

int	ft_dq_sanit(t_mirror *cmd)
{
	t_iter	val;
	t_mirror	buffer;

	ft_bzero(&val, sizeof(val));
	buffer.str = ft_calloc(ft_strlen(cmd->str) + 1, 1);
	buffer.mirror = ft_calloc(ft_strlen(cmd->mirror) + 1, 1);
	if (!buffer.str || !buffer.mirror)
		return (-1);
	while (cmd->str[val.i])
	{
		if (cmd->str[val.i] == '"' && cmd->mirror[val.i] == '0')
		{
			val.i++;
			continue;
		}
		buffer.str[val.j] = cmd->str[val.i];
		buffer.mirror[val.j++] = cmd->mirror[val.i++];
	}
	buffer.str[val.j] = 0;
	buffer.mirror[val.j] = 0;
	ft_free_and_replace(cmd, &buffer);
	return (0);
}

char	*ft_get_word(t_iter *vals, t_mirror *cmd, char *var)
{
	vals->i++;
	vals->j = vals->i;
	/**
	 * mientras 1. el valor exista && (el caracter no sea un espacio Y no sea numero)
	 */
	while (cmd->str[vals->j] && (cmd->str[vals->j] != ' ' || ft_isalnum(cmd->str[vals->j])))
		vals->j++;
	var = ft_substr(cmd->str, vals->i, vals->j - vals->i);
	if (!var)
		return (NULL);
	return (var);
}

char	*ft_new_mirror_piece(char *valor)
{
	int		i;
	char	*tmp_mirror;

	i = 0;
	tmp_mirror = ft_calloc((ft_strlen(valor) + 1), 1);
	if (!tmp_mirror)
		return (NULL);
	while (valor[i])
		tmp_mirror[i++] = '3';
	tmp_mirror[i] = 0;
	return (tmp_mirror);
}

int	ft_reconstruir_mirror(t_iter *vals, t_mirror *cmd, char *valor)
{
	char	*tmp_mirror;
	char	*antes;
	char	*resto;
	char	*tmp;
	char	*final;

	tmp_mirror = ft_new_mirror_piece(valor);
	antes = ft_substr(cmd->mirror, 0, vals->i - 1);
	resto = ft_substr(cmd->mirror, vals->j, ft_strlen(cmd->mirror) - vals->j);
	if (!antes || !resto)
		return (-1);
	tmp = ft_strjoin(antes, tmp_mirror);
	if (!tmp)
		return (-1);
	final = ft_strjoin(tmp, resto);
	if (!final)
		return (-1);
	free(tmp_mirror);
	free(antes);
	free(resto);
	free(tmp);
	free(cmd->mirror);
	cmd->mirror = final;
	return (0);	
}

int	ft_construir_str(t_iter *vals, t_mirror *cmd, char * valor)
{
	char	*antes;
	char	*resto;
	char	*tmp;
	char	*final;

	antes = ft_substr(cmd->str, 0, vals->i - 1);
	resto = ft_substr(cmd->str, vals->j, ft_strlen(cmd->str) - vals->j);
	if (!antes || !resto)
		return (-1);
	tmp = ft_strjoin(antes, valor);
	if (!tmp)
		return (-1);
	final = ft_strjoin(tmp, resto);
	if (!final)
		return (-1);
	ft_reconstruir_mirror(vals, cmd, valor);
	free(antes);
	free(resto);
	free(tmp);
	free(cmd->str);
	cmd->str = final;
	return (0);
}

int	ft_expand(t_mirror *cmd)
{
	t_iter	vals;
	char	*var;
	char	*valor;

	ft_bzero(&vals, sizeof(vals));
	var = NULL;
	valor = NULL;
	/*var = ft_calloc(sizeof(char), PATH_MAX);
	if (!var)
		return (-1);*/
	//get word to expand
	while (cmd->str[vals.i])
	{	//echo $HOME
		if (cmd->str[vals.i] == '$' && cmd->mirror[vals.i] == '1')//$ -> i = 5
		{
			var = ft_get_word(&vals, cmd, var);
			valor = getenv(var);
			if (!valor)
				valor = "";
			free(var);
			ft_construir_str(&vals, cmd, valor);
		}
		vals.i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mirror	cmd;
	char	*line;
	
	line = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line)
			return (-1);
		cmd.str = line;
		cmd.mirror = ft_create_mirror(line);
		ft_printf("mirror al iniciar: %s\n", cmd.mirror);
		if (ft_sq_sanit(&cmd) == -1)
			return (-1);
		ft_printf("linea del readline = %s\n", cmd.str);
		ft_printf("mirror = %s\n", cmd.mirror);
		if (ft_dq_sanit(&cmd) == -1)
			return (-1);
		ft_printf("linea del readline despues de dq_sanit = %s\n", cmd.str);
		ft_printf("mirror = %s\n", cmd.mirror);
		ft_expand(&cmd);
		ft_printf("cmd->str after expanding: %s\n", cmd.str);
		ft_printf("cmd->mirror after expanding: %s\n", cmd.mirror);
		free(cmd.str);
		free(cmd.mirror);
	}
	

}

//cc -I../../include -I../../ ft_create_mirror.c -lreadline -L../../libft -L../../libftprintf -lftprintf -lft