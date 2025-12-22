#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

/*
	handler to block Ctrl+\
*/
void handler_sigaction(int sig)
{
	(void)sig;
	//write(1, &sig, 1);
}

/*
	setup handler for crtl+\
*/
void init_sigaction()
{
	struct	sigaction sa;
	size_t	s;
	char	**p;

	s = 0;
	p = (char **)&sa;
	while (s < sizeof(sigaction))
	{
		*p++ = 0;
		s++;
	}
	sa.sa_handler = &handler_sigaction;
	sigaction(SIGQUIT, &sa, (void *)0);
}

void init()
{
	init_sigaction();
}
void update()
{
}

void draw()
{
	write(1, "> ", 2);
}

/*
	
*/
void readconsole_events()
{
	size_t	bytes_read;
	char	read_buffer[6];

	bytes_read = read(0, read_buffer, sizeof(read_buffer) - 1);
	if ((bytes_read >1) && (read_buffer[0] == 'e' && read_buffer[1] == 'x'))
		exit(0);
}

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;

	init();
	while(1)
	{
		update();
		draw();
		readconsole_events();
	}

	return (0);
}
