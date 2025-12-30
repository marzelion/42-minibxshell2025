/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:20:47 by marcfer3          #+#    #+#             */
/*   Updated: 2025/12/17 16:20:47 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

char	*ft_current_directory_history_path(void)
{
	char	*pwd_dir;
	char	*history_path;

	pwd_dir = ft_calloc(PATH_MAX, sizeof(char));
	pwd_dir = getcwd(pwd_dir, PATH_MAX);//recordar q path_max es un int definido en el sistema o en C no m acuerdo
	if (!pwd_dir)
		ft_exit(1);
	//tengo que sumar el current pwd y añadirle el nombre "minishell_history"
	history_path = NULL;
	history_path = ft_strjoin(pwd_dir, "/.minishell_history");
	if (!history_path)
	{
		ft_printf("error creating string for readline_history file\n");
		if (pwd_dir)
			free(pwd_dir);
		ft_exit(1);
	}
	if (pwd_dir)
		free(pwd_dir);
	return (history_path);
	//--------------------------------------------------------------------------------------
	/*SI QUISIERA GUARDAR EL ARCHIVO DEL HISTORIAL EN HOME, DE FORMA QUE TODOS LOS USUARIOS
	TENGAN ACCESO A SU PROPIO HISTORIAL INDEPENDIENTEMENTE DESDE DONDE EJECUTEN MINISHELL
	
	IGUALMENTE CREO QUE ES VALIDO QUE EL HISTORIAL SE GUARDE DENTRO DEL DIRECTORIO DEL PROYECTO*/
	/*if(home)
	{
		history_path = ft_calloc(ft_strlen(home) + ft_strlen("/.minishell_history" + 1, sizeof(char)));
		if (!history_path)
			ft_exit(1);
		ft_strcpy(history_path, home);
		ft_strcat(history_path, "./minishell_history");
		
	}
	else
		history_path = ft_srtdup("./minishell_history");*/
	//---------------------------------------------------------------------------------
}

void	ft_check_builtins(char **line_argvs, int i, char **envp)
{
	if (ft_strncmp(line_argvs[i], "pwd", 4) == 0)
		ft_pwd();
	else if (ft_strncmp(line_argvs[i], "env", 5) == 0)
		ft_env(envp);
	else if (ft_strncmp(line_argvs[i], "cd", 3) == 0)
		ft_cd(line_argvs);
	else if (ft_strncmp(line_argvs[i], "echo", 5) == 0)
		ft_echo(line_argvs);
}