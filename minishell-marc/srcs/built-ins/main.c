/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                      	                              +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:20:31 by marcfer3          #+#    #+#             */
/*   Updated: 2025/12/30 17:16:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	debug_string(char *msg, char **string)
{
	int	i = 0;

	if (msg)
		ft_printf("%s", msg);
	while (string[i])
	{
		ft_printf("%s\n", string[i]);
		i++;
	}
}

void	ft_non_interactive_minishell(char **argvs, char **envp, int argc, char *program_name)
{
	char	*line;
	char	**argvs_line;
	char	*tmp;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_exit(1);
	else if (pid == 0)
	{
		line = NULL;
		argvs_line = NULL;
		if (argvs[1] == NULL)
		{
			ft_printf("minishell no interactivo > ");
			line = get_next_line(STDIN_FILENO);
			if (!line)
				return ;
			tmp = line;
			line = ft_strtrim(line, "\n");
			free(tmp);
			argvs_line = ft_split(line, ' ');
			if (!argvs_line)
			{
				ft_printf("error from ft_split\n");
				ft_exit(1);
			}
		}
		else if (argvs && argvs[1])
		{
			argvs_line = ft_ignore_argv1_argv2(argvs, argc, program_name);
			if (!argvs_line)
				ft_exit(0);
		}
		if (argvs_line[0] && (ft_strncmp(argvs_line[0], "exit", 5) == 0))
		{
			ft_free_array(argvs_line);
			ft_exit(0);
		}
		else if (argvs_line)
			ft_check_builtins(argvs_line, 0, envp);
		ft_free_array(argvs_line);
		free(line);
		ft_exit(0);
	}
	else
		wait(NULL);
}

void	ft_interactive_minishell(char **envp, int argc, char *program_name)
{
	int		i;
	char	*line;
	char	*history_path;
	char	**line_argvs;

	history_path = ft_current_directory_history_path();//esta es la ruta donde estará el archivo donde se guardia el historial
	i = 0;
	//INICIALIZAR SISTEMA DE HISTORIAL EN MEMORIA
	using_history();
	//CARGA REL HISTORIAL PREVIO SI EXISTE UN ARCHIVO PREVIO
	read_history(history_path);//carga los comandos anteriores, desde el archivo a la RAM
	// -----------------------------------------------
	//añadir sigaction aqui porq cambia como se maneja la señal
	if (ft_change_signals() != 0)
		return ;
	//-------------------------------------------------
	line_argvs = NULL;
	while (1)
	{
		//pipex.run
		/**/
		line = readline("> ");///--------->>> USAR PS1

		if (!line)//EOF, cntlr+D
			break ;
		if (line && line[0] != '\0')
		{
			add_history(line);
			line_argvs = ft_split(line, ' ');
			if ((line_argvs[0]) && (ft_strncmp(line_argvs[0], "exit", 5) == 0))
			{
				ft_free_array(line_argvs);
				free(line);
				break ;
			}
			if (ft_strncmp(line_argvs[0], program_name, ft_strlen(program_name) + 1) == 0)
				ft_non_interactive_minishell(line_argvs, envp, argc, program_name);
			if (line_argvs)
				ft_check_builtins(line_argvs, i, envp);
			ft_free_array(line_argvs);
		}
		free(line);
	}
	write_history(history_path);
	clear_history();
	free(history_path);
	free(program_name);
}

char	*ft_program_name(char *program_name, char **argvs)
{
	program_name = ft_strdup(argvs[0]);
	if (!program_name)
		ft_exit(1);
	return (program_name);
}

int	main(int argc, char **argvs, char **envp)
{
	char	*program_name;

	program_name = NULL;
	program_name = ft_program_name(program_name, argvs);
	if (argvs[1])
	{
		ft_non_interactive_minishell(argvs, envp, argc, program_name);
		ft_exit(0);
	}
	else if (!argvs[1])
	{
		if (isatty(STDIN_FILENO))
			ft_interactive_minishell(envp, argc, program_name);
		else
			ft_non_interactive_minishell(argvs, envp, argc, program_name);
	}
	return (0);
}

/*
*/