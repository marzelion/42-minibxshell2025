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

#include <signal.h>
#include <unistd.h>//read()
#include <stdio.h>//printf(), fflush()
#include <string.h>//for strcmp()
#include <stddef.h>// for size_t
#include <stdlib.h>//exit

void handle_signal(int sig)
{
}

/*
 * struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };

 *
 * */
int main()
{
	size_t s;
	char **p;
	char	read_buffer[6];
	ssize_t	bytes_read;
	struct sigaction sa;

	s = 0;
	p = (char **)&sa;
	while (s < sizeof(sa))
	{
		*p++ = 0;		
		s++;	
	}
	sa.sa_handler = &handle_signal;
	sigaction(SIGQUIT, &sa, (void *)0);

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
}