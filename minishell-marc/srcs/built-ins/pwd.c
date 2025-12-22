/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:18:51 by marcfer3          #+#    #+#             */
/*   Updated: 2025/12/12 17:18:51 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../../minishell.h"

void	ft_pwd(void)
{
	char	*current_path;

	current_path = ft_calloc(PATH_MAX, sizeof(char));
	if (getcwd(current_path, PATH_MAX) == NULL)
	{
		free(current_path);
		perror("getcwd");
	}
	ft_printf("current pwd: %s\n", current_path);
	free(current_path);
}