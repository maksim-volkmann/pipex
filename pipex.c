#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>



void	child_process(int *pipe_fd, char *src_file, char *first_cmd)
{
	int src_fd;

	src_fd = open(src_file, O_RDONLY);
	if(src_fd == -1)
	{
		perror("Open failed");
		exit(EXIT_FAILURE);
	}
	if(dup2(src_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 failed.");
		close(src_fd);
		exit(EXIT_FAILURE);
	}
	close(src_fd);
	if(dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed.");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[1]);
	run_command();

}



// int main(int ac, char *av[], char *ep[])
// {
// 	int fd[2];
// 	// int fd_src;
// 	// int fd_dest;
// 	pid_t pid1;

// 	if (ac != 5)
// 	{
// 		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	// fd_src = open(av[1], O_RDONLY);
// 	// if (fd_src == -1)
// 	// {
// 	// 	perror("open");
// 	// 	exit(EXIT_FAILURE);
// 	// }
// 	// fd_dest = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	// if (fd_dest == -1)
// 	// {
// 	// 	perror("open");
// 	// 	close(fd_src);
// 	// 	exit(EXIT_FAILURE);
// 	// }
// 	if (pipe(fd) == -1)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}
// 	pid1 = fork();
// 	if(pid1 == 0)
// 	{
// 		child_process(fd[0]);
// 	}
// 	if(pid1 > 1)
// 	{
// 		//parent process
// 	}
// 	// close(fd_src);
// 	// close(fd_dest);
// }

int main(int ac, char *av[], char *ep[])
{
	int pipe_fd[2];
	pid_t pid1;

	if (ac != 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		exit(EXIT_FAILURE);
	}

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if(pid1 == 0)
		child_process(pipe_fd, av[1], av[2]);
	waitpid(pid1, NULL, 0);
	parent_process(pipe_fd, av[4], av[3]);

}

