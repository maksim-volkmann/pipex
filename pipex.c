#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "pipex.h"


// int main(int ac, char *av[], char *ep[])
int main(int ac, char *av[], char *ep[])
{
	int number_of_cmd;
	int number_of_pipes;
	int *fd;
	pid_t pid;
	int i;

	// if (ac != 5)
	// {
	// 	write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 39);
	// 	return 1;
	// }


	number_of_cmd = ac - 3;
	ft_printf("Number of commands: %d\n", number_of_cmd);

	number_of_pipes = number_of_cmd - 1;
	ft_printf("Number of pipes: %d\n", number_of_pipes);

	fd = malloc(sizeof(int) * 2 * number_of_pipes);
	if (!fd)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	printf("Number of fds: %d\n", 2 * number_of_pipes);
	// printf("fd: %d\n", fd);
	pid = fork();
	// printf("Parent Process: %d\n", getpid());
	ft_printf("PID: %d\n", pid);

	while(i < number_of_pipes)
	{
		pipe(fd + 2 * i);
		i++;
	}
}

