/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:39:10 by marcfer3          #+#    #+#             */
/*   Updated: 2026/01/16 00:23:00 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* Standard C Library */
#include <stdio.h>      /* printf, perror */
#include <stdlib.h>     /* malloc, free, exit, getenv */
#include <string.h>     /* strerror */
#include <unistd.h>     /* write, access, open, read, close, fork, getcwd, chdir, dup, dup2, pipe, isatty, ttyname, ttyslot */
/* File operations */
#include <fcntl.h>      /* open */
#include <sys/types.h>  /* open, stat, fork, wait, signal */
#include <sys/stat.h>   /* stat, lstat, fstat, unlink */
/* Process management */
#include <sys/wait.h>   /* wait, waitpid, wait3, wait4 */
#include <signal.h>     /* signal, sigaction, sigemptyset, sigaddset, kill */
/* Directory operations */
#include <dirent.h>     /* opendir, readdir, closedir */
/* Terminal control */
#include <termios.h>    /* tcsetattr, tcgetattr */
#include <sys/ioctl.h>  /* ioctl */
/* Terminal capabilities (curses/terminfo) */
#include <term.h>       /* tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs */
/* GNU Readline Library */
#include <readline/readline.h>      /* readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay */
#include <readline/history.h>       /* add_history */
//old libraries
#include "libraries/ft_printf/ft_printf.h"
#include "libraries/full_libft/libft.h"
#include "libraries/gnl/get_next_line.h"

extern volatile sig_atomic_t global_signal_received;
/*
volatile-> palabra clave de C que le dice al compilador que no optimice esta variable:
	los signal handlers pueden cambiar la variable en cualquier momento,
	sin volatile, el compilador podria asumir que la variable no cambia y guardarla en un registro,
	nunca viendo el cambio
sig_atomic_t -> tipo de dato entero especial definido en signal.h
*/

//funciones
void	ft_exit(int code);
void	ft_pwd(void);
void	ft_env(char **envs_array);
int		main(int argc, char **argv, char **envp);
void	ft_echo(char **argvs);
void	ft_free_array(char **array);
void	ft_cd(char **argvs);
void	ft_cd_path(char *path);
char	*ft_current_directory_history_path(void);
void	ft_check_builtins(char **line_argvs, int i, char **envp);
void	ft_interactive_minishell(char **envp, int argc, char *program_name);
int		ft_change_signals();
char	**ft_ignore_argv1_argv2(char **argvs, int argc, char *program_name);
void	ft_non_interactive_minishell(char **argvs, char **envp, int argc, char *program_name);

#endif