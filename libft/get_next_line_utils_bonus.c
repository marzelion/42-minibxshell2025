/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrtinez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:34:26 by smrtinez          #+#    #+#             */
/*   Updated: 2025/07/07 11:39:11 by smrtinez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

size_t	ft_strlen_delim(char *s, char c)
{
	size_t	result;

	result = 0;
	while (*s && (*s != c))
	{
		result++;
		s++;
	}
	return (result);
}

char	*ft_strncpygl(char *dest, char *src, size_t n)
{
	char	*pudest;

	pudest = dest;
	while (n--)
		*pudest++ = *src++;
	*pudest = '\0';
	return (dest);
}

char	*ft_strjoingl(char *s1, char *s2)
{
	char	*result;
	size_t	s1len;
	size_t	s2len;

	if (!s1 && !s2)
		return ((void *)0);
	s1len = 0;
	s2len = 0;
	if (s1)
		s1len = ft_strlen_delim(s1, '\0');
	if (s2)
		s2len = ft_strlen_delim(s2, '\0');
	result = (char *)malloc(s1len + s2len + 1);
	if (!result)
		return ((void *)0);
	result[0] = '\0';
	if (s1len)
		ft_strncpygl(result, s1, s1len);
	if (s2len)
		ft_strncpygl(result + s1len, s2, s2len);
	return (result);
}

int	have_nl(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

/*
	Singleton buffer: Read about it
	Singleton for buffer, initialized on first call to memset(0)
*/
/*
static const char	*getbuffer(void)
{
	static char	buffer[BUFFER_SIZE];
	static char	*pbuffer;

	if (pbuffer != buffer)
	{
		pbuffer = buffer + BUFFER_SIZE - 1;
		while (pbuffer >= buffer)
			(*(unsigned char *)pbuffer--) = (unsigned char) 0;
	}
	return (pbuffer);
}
*/
/*
	Singleton buffer: Read about it. 
	Initialized on the first call.
 This corrected implementation of getbuffer_todo_utilsc properly 
	manages a static buffer and a pointer within its limits 
while maintaining the remainder buffer for the next call. 
test code 
int main() {
    char *buffer_pointer;

    // Initialize the buffer
    getbuffer_todo_utilsc(NULL);
    buffer_pointer = getbuffer_todo_utilsc(&buffer_pointer);
    snprintf(buffer_pointer, 
	BUFFER_SIZE - (buffer_pointer - getbuffer_todo_utilsc(NULL)), 
	"Hello, World!");
    printf("Buffer content: %s\n", getbuffer_todo_utilsc(NULL));
    // Update the pointer to the next position
    buffer_pointer += 13; // Move the pointer to the end of the current string
    // Get the buffer again to continue writing
    buffer_pointer = getbuffer_todo_utilsc(&buffer_pointer);
    snprintf(buffer_pointer, 
	BUFFER_SIZE - (buffer_pointer - getbuffer_todo_utilsc(NULL)), 
	" This is a test.");
    printf("Buffer content after update: %s\n", getbuffer_todo_utilsc(NULL));

char	*getbuffer_todo_utilsc(char **prm)
{
	static char	buffer[BUFFER_SIZE];
	static char	*pb;

	if ((pb == NULL) || (pb < buffer) || (pb >= (buffer + BUFFER_SIZE)))
	{
		pb = buffer + BUFFER_SIZE - 1;
		while (pb >= buffer)
			(*(unsigned char *)pb--) = (unsigned char) 0;
		pb = buffer;
	}
	if (prm != NULL)
	{
		if ((*prm < buffer) || (*prm >= (buffer + BUFFER_SIZE)))
			pb = buffer;
		else
			pb = *prm;
	}
	if (prm != NULL)
		*prm = pb;
	return (pb);
}

char	*allocate_readparagraph(int fd, char *readbuffer, size_t *bytesread)
{
	char	*line;
	char	*pparagraph;

	line = NULL;
	pparagraph = readbuffer;
	if (readbuffer < getbuffer_todo_utilsc(&pparagraph))
	{
		return (line);
	}
	else
	{
		*bytesread = read(fd, (char *)readbuffer, BUFFER_SIZE);
		pparagraph += *bytesread;
		getbuffer_todo_utilsc(&pparagraph);
		if ((*bytesread == -1ul) || (!*bytesread))
			return ((void *)0);
		pparagraph = ft_strrchr(readbuffer, '\n');
	}
	
return ((void *)0);
}
*/
