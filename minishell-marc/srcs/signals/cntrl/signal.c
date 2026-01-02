/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .c                                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcfer3 <marcfer3@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:56:07 by marcfer3          #+#    #+#             */
/*   Updated: 2025/12/12 18:56:07 by marcfer3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*void handle_signal(int sig)
{
	(void)sig;
}
 * struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };
int	ft_change_signals(void)
{
	size_t s;
	char **p;
	//char	read_buffer[6];
	//ssize_t	bytes_read;
	struct sigaction sa;

	s = 0;
	p = (char **)&sa;
	while (s < sizeof(sa))
	{
		*p++ = 0;		
		s++;	
	}
	sa.sa_handler = &handle_signal;
	if (sigaction(SIGQUIT, &sa, (void *)0) == -1)
		return (1);
	while (1)
	{
		write(1, "> ", 2);
		bytes_read = read(0, read_buffer, sizeof(read_buffer) - 1);
		if (bytes_read == -1)
			exit(1);
		read_buffer[bytes_read] = '\0';
		if (strcmp(read_buffer, "exit\n") == 0)
		{
			exit(0);
		}
	}
	return (0);
}*/

int	ft_change_signals(void)
{
	struct	sigaction sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = SIG_IGN;//SIGN_IGN is builtin call to ignore signal
	sigaction(SIGQUIT, &sa, NULL);
	return (0);
}