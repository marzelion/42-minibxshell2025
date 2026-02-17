/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envmgr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:02:46 by smrtinez          #+#    #+#             */
/*   Updated: 2025/10/09 11:02:48 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVMGR_H
# define ENVMGR_H

#include <sys/types.h>
#include <stddef.h>
#include "mx_utils.h"

typedef struct s_envmanager
{
	int		pd[3];
	char	**envpbase;
	char	**envp;
	char	**(*find)(struct s_envmanager *p, char *key, char **val);
	char	**(*create)(struct s_envmanager *p, char *kvpair);
	char	**(*print)(struct s_envmanager *p, char **kventry);
	char	*(*v)(struct s_envmanager *p, char *key);
}	t_envmanager, t_evm;

/* envmgr.c*/

int				is_validkey(const char *n);

t_envmanager	*t_evm_dtor(t_envmanager *p);

t_envmanager	*t_evm_ctor(t_envmanager *p, char **envp, int pipeok);

char			**t_evm_print(t_envmanager *p, char **kventry);

char			**t_evm_realloc(t_evm *p, char **envp, char *add, ssize_t tsz);

/* envmgr_crud.c*/

int				t_evm_default(t_envmanager *p);

char			**t_evm_find(t_envmanager *p, char *key, char **val);

char			**t_evm_create(struct s_envmanager *p, char *kvpair);

#endif
