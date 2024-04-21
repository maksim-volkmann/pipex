#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int ac, char *av[], char *ep[])
{
	int fd[2];
	int fd_src;
	int fd_dest;
	pid_t pid1;

	if (ac != 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		exit(EXIT_FAILURE);
	}
	fd_src = open(av[1], O_RDONLY);
	if (fd_src == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	fd_dest = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_dest == -1)
	{
		perror("open");
		close(fd_src);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if(pid1 == 0)
	{
		//child process
	}
	if(pid1 > 1)
	{
		//parent process
	}
	close(fd_src);
	close(fd_dest);
}

