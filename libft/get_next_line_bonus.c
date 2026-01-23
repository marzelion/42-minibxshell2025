/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:54:11 by smrtinez          #+#    #+#             */
/*   Updated: 2025/07/02 16:27:39 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_keep(char *buffer)
{
	size_t	sz;
	size_t	ln;
	size_t	total;

	if (!buffer)
		return ((void *)0);
	sz = ft_strlen_delim(buffer, '\0');
	ln = ft_strlen_delim(buffer, '\n');
	total = sz - ln + 1;
	if ((total == 0) || (ln > sz))
		return (buffer);
	ln++;
	ft_strncpygl(buffer, buffer + ln, total - 1);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*paragraph;
	int		ln;

	ln = ft_strlen_delim(buffer, '\n');
	if (buffer[ln] == '\n')
		ln++;
	paragraph = (char *)malloc(sizeof(char) * (ln + 1));
	if (!paragraph)
		return ((void *)0);
	ft_strncpygl(paragraph, buffer, ln);
	return (paragraph);
}
/*
 *
	if ((fd < 0) || (fd > 256) || (BUFFER_SIZE <= 0))
 * */

void	*release_buffer(void **b, void **b1)
{
	if (!b && !b1)
		return (NULL);
	if (b)
	{
		if (*b)
		{
			free(*b);
			*b = NULL;
		}
	}
	if (b1)
	{
		if (*b1)
		{
			free (*b1);
			*b1 = NULL;
		}
	}
	if (!b)
		return (*b1);
	return (*b);
}

/*
	NO SAFETY, RTFM
	if (!bufsize)
		bufsize = 1;
		* 
	if (!buffer)
		 buffer = (malloc(sizeof(char *)));
	if (!buffer)
		return (NULL);
	if ((*buffer) == NULL)
	{
		(*buffer) = malloc((bufsize + 1) * sizeof(char));
		if (!*buffer)
		{
			*buffer = NULL;
			return (*buffer);
			//return (NULL);
		}
		*buffer = '\0';
	}
	return (*buffer);		* 
*/
char	*newstr(char **buffer, size_t bufsize)
{
	char	*pstr;

	if (!*buffer)
	{
		pstr = malloc((bufsize + 1) * sizeof(char));
		if (!pstr)
			return (NULL);
		*buffer = pstr;
		while (pstr != ((*buffer) + bufsize + 1))
			(*pstr++) = '\0';
		pstr = NULL;
	}
	return (*buffer);
}

/*
 * 		//    *pstr = '\0';
		//    *buffer = pstr;
//	char			rbuf[BUFFER_SIZE + 1];
	//while (!have_nl(newstr(&buffer, 0)) && newstr(&rbuf, BS) && bts)
*/
char	*get_next_line(int fd)
{
	char			*rbuf;
	int				bts;
	static char		*buffer[FD_SETSIZE];
	char			*tmp;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return ((void *)0);
	bts = 1;
	rbuf = NULL;
	while (!have_nl(newstr(&buffer[fd], 0)) && bts)
	{
		bts = read(fd, newstr(&rbuf, BS), BUFFER_SIZE);
		if ((bts == -1) || ((!bts) && (*buffer[fd] == '\0')))
			return (release_buffer((void **)&rbuf, (void **)&buffer[fd]));
		tmp = ft_strjoingl(buffer[fd], ft_strncpygl(rbuf + bts, "", 0) - bts);
		release_buffer((void **)&rbuf, (void **)&buffer[fd]);
		buffer[fd] = tmp;
	}
	tmp = get_line(buffer[fd]);
	if (!tmp)
		return (release_buffer(NULL, (void **)&buffer[fd]));
	buffer[fd] = get_keep(buffer[fd]);
	if (*buffer[fd] == '\0')
		release_buffer(NULL, (void **)&buffer[fd]);
	return (tmp);
}
/*
 * WATCHOUT LINE 148 and LINE 149 ABOVE!!!!!!! ADDED FOR PIPEX!!!!!
 * !!!!!!!!!!!!!!!!!!!!!!!!! 
 * if (buffer[fd])
		release_buffer(NULL, (void **)&buffer[fd]);	
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
char	*get_next_line(int fd)
{
	char		*pbuf;
	size_t		read;

	read = 0;

	if ((fd < 0) || (fd > 256) || (BUFFER_SIZE <= 0))
		return ((void *)0);
	pbuf = allocate_readparagraph(fd, getbuffer_todo_utilsc(NULL), &read);
while (bytesread > 0)
	{
		//write (STDOUT_FILENO, buffer, bytesread);
		bytesread = read (fd, (char *)pbuffer, BUFFER_SIZE);
	}
	return ((char *)pbuf);
}
*/
