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

void	ft_non_interactive_minishell(char **argvs, char **envp, int argc)
{
	char	*line;
	char	**argvs_line;

	/*
	opcion 1: desde minishell escribo -c ->leo siguiente entrada
	opcion 2: desde minishell escribo -c + comandos
	opcion 3: ./minishell -c +comandos
	*/
	line = NULL;
	argvs_line = NULL;
	if (argvs == NULL)
	{
		write(1, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			return ;
		argvs_line = ft_split(line, ' ');
		if (!argvs_line)
		{
			ft_printf("error from ft_split\n");
			ft_exit(1);
		}
	}
	else if (argvs)
	{
		//problema-> los argvs recibidos en el momento de ejecutar el programa van a tener argv0 y argv1 que no quiero para mi argvs_line
		//solucion: llamar una funcion que mira el argv0 y argv1 para ignorarlos a la hora de crear el argvs_line
		argvs_line = ft_ignore_argv1_argv2(argvs, argc);
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
	//./minishell -c comando detalles
}

void	ft_interactive_minishell(char **envp, int argc)
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
		if (line)
		{
			/*
			para los built-ins, pasarle argc, argv, envp
			*/

			/*
			man execve -> exemplo de codigo con scripts
			*/
			add_history(line);
			line_argvs = ft_split(line, ' ');
			if ((line_argvs[0]) && (ft_strncmp(line_argvs[0], "exit", 5) == 0))
			{
				ft_free_array(line_argvs);
				free(line);
				break ;
			}
			if (ft_strncmp(line_argvs[0], "-c", 3) == 0)
				ft_non_interactive_minishell(line_argvs, envp, argc);
			if (line_argvs)
				ft_check_builtins(line_argvs, i, envp);
			/*Si el comando no es un built-in, llamar al pipex
			Si el comando ES un built-in, llamar al pipex con el execve de ./minishell 'built-in'
			siempre se hará un fork+execve*/
			ft_free_array(line_argvs);
			//------------------------
			//variable global != 0 --> hacer algo
			//-------------------------
		}
		free(line);
	}
	write_history(history_path);
	clear_history();
	free(history_path);
}

int	main(int argc, char **argvs, char **envp)
{
	if (argvs[1] && ft_strncmp(argvs[1], "-c", 3) == 0)
	{
		ft_non_interactive_minishell(argvs, envp, argc);
		ft_exit(0);
	}
	else if (!argvs[1])
	{
		if (isatty(STDIN_FILENO))
			ft_interactive_minishell(envp, argc);
		else
			ft_non_interactive_minishell(argvs, envp, argc);
	}
	return (0);
}