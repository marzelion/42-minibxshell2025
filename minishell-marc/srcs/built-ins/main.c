/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:20:31 by marcfer3          #+#    #+#             */
/*   Updated: 2025/12/27 18:00:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	main(int argc, char **argvs, char **envp)
{
	int		i;
	char	*line;
	char	*history_path;
	char	**line_argvs;

	(void)argc;
	history_path = ft_current_directory_history_path();//esta es la ruta donde estará el archivo donde se guardia el historial
	i = 0;
	//INICIALIZAR SISTEMA DE HISTORIAL EN MEMORIA
	using_history();
	//CARGA REL HISTORIAL PREVIO SI EXISTE UN ARCHIVO PREVIO
	read_history(history_path);//carga los comandos anteriores, desde el archivo a la RAM
	while (1)
	{
		/*
		1. iniciar llamada con using_history()
		2. añadir entradas con add_history(line)
			add_history duplica la cadena internamente, así que puedo hacer free
			, como con dup2
		3. write_history(path) para escribir en el archivo y clea history
		para liberar la memoria de la lista
		4. control de tamaño-> stifle_history --> limita el numero de entradas
		5. read_history() y write_history() devuelven 0 en éxito, valor distint en error*/
		line = readline("> ");
		if (!line)//EOF, cntlr+D
			break;
		if (line)
		{
			add_history(line);
			line_argvs = ft_split(line, ' ');
			if (ft_strncmp(line_argvs[i], "pwd", 4) == 0)
				ft_pwd();
			else if (ft_strncmp(line_argvs[i], "envp", 5) == 0)
				ft_env(envp);
			else if (ft_strncmp(line_argvs[i], "cd", 3) == 0)
				ft_cd(line_argvs);
			else if (ft_strncmp(line_argvs[i], "echo", 5) == 0)
				ft_echo(argvs);
			//ft_free_array(line_argvs);
			ft_free_array(line_argvs);
		}
		free(line);
	}
	write_history(history_path);
	clear_history();
	free(history_path);
	return (0);
}