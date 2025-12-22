/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:01:34 by marcfer3          #+#    #+#             */
/*   Updated: 2025/12/17 13:01:34 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	PATH RELATIVOS O ABSOLUTOS
	RELATIVO->	Ruta desde el directorio donde estoy
			No comienza con /
			Depende de donde estoy ubicado
			Usa . (directorio actual) y .. (directorio padre)

	ABSOLUTO->	Ruta completa desde la raiz del sistema
			comienza con /
			es una dirección completa
*/
/*char	*ft_delete_last_word(char *path)
{
	char	**pwd_words;
	char	*new_pwd;
	int		word_count;
	int		i;

	pwd_words = ft_split(path, "/");
	if (pwd_words == NULL)
		ft_exit(1);
	word_count = 0;
	while (pwd_words[word_count])
		word_count++;
	word_count--;
	//need a funcion that concatenates strings till word_count
	i = 0;
	while (i < word_count)
	{
		new_pwd = ft_strjoin(pwd_words[i], pwd_words[i + 1]);
		i++;
	}
	ft_free_array(pwd_words);
	free(path);
	return (new_pwd);
}*/

void	ft_cd_path(char *path)
{
	char	*new_pwd;
	char	*old_pwd;
	
	//ft_printf("%s \n", path);
	old_pwd = ft_calloc(PATH_MAX, sizeof(char));
	if (!old_pwd)
		ft_exit(1);
	if (getcwd(old_pwd, PATH_MAX) == NULL)
	{
		free(old_pwd);
		perror("pwd");
		ft_exit(1);
	}
	if (chdir(path) != 0)
	{
		perror("cd");
		ft_exit(1);
	}
	new_pwd = ft_calloc(PATH_MAX, sizeof(char));
	if (!new_pwd)
		ft_exit(1);
	if (getcwd(new_pwd, PATH_MAX) == NULL)
	{
		free(new_pwd);
		perror("pwd");
		ft_exit(1);
	}
	else
	{
		setenv("PWD", new_pwd, 1);
		setenv("OLD_PWD", old_pwd, 1);
		free(new_pwd);
		free(old_pwd);
	}
}

void	ft_cd(char **argvs)
{
	//cd, cd ., cd .., cd path
	//old pwd
	//pwd
	if (!argvs[2])
		return ;
	else if (ft_strncmp(argvs[2], ".", 2) == 0)
		return ;
	else
		ft_cd_path(argvs[2]);
}