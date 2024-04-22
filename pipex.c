/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:04:05 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/22 19:56:01 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if (access(filename, F_OK | R_OK) == 0)
//if (access(filename, F_OK | W_OK) == 0

#include "pipex.h"
// parent_process(pipe_fd, av[4], av[3]);
// void	parent_process(int *pipe_fd, char *dest_file, char *second_cmd, char **ep)
// {
// 	int dest_fd;

// 	close(pipe_fd[1]);
// 	dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 	if(dest_fd == -1)
// 	{
// 		perror("Open failed");
// 		exit(EXIT_FAILURE);
// 	}
// 	if(dup2(dest_fd, STDOUT_FILENO) == -1)
// 	{
// 		perror("dup2 failed.");
// 		close(dest_fd);
// 		exit(EXIT_FAILURE);
// 	}
// 	close(dest_fd);
// 	if(dup2(pipe_fd[0], STDIN_FILENO) == -1)
// 	{
// 		perror("dup2 failed.");
// 		exit(EXIT_FAILURE);
// 	}
// 	close(pipe_fd[0]);
// 	run_command(second_cmd, ep);
// 	exit(0);
// }

// void	child_process(int *pipe_fd, char *src_file, char *first_cmd, char **ep)
// {
// 	int src_fd;

// 	close(pipe_fd[0]);
// 	if (access(src_file, F_OK | R_OK) != 0)
// 	{
// 		perror("Cant access src file or does not exists.");
// 		exit(EXIT_FAILURE);
// 	}
// 	src_fd = open(src_file, O_RDONLY);
// 	if(src_fd == -1)
// 	{
// 		perror("Open failed");
// 		exit(EXIT_FAILURE);
// 	}
// 	if(dup2(src_fd, STDIN_FILENO) == -1)
// 	{
// 		perror("dup2 failed.");
// 		close(src_fd);
// 		exit(EXIT_FAILURE);
// 	}
// 	close(src_fd);
// 	if(dup2(pipe_fd[1], STDOUT_FILENO) == -1)
// 	{
// 		perror("dup2 failed.");
// 		exit(EXIT_FAILURE);
// 	}
// 	close(pipe_fd[1]);
// 	run_command(first_cmd, ep);
// }



// int main(int ac, char **av, char **ep)
// {
// 	int status;
// 	int pipe_fd[2];
// 	pid_t pid1;

// 	if (ac != 5)
// 	{
// 		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (pipe(pipe_fd) == -1)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}
// 	pid1 = fork();
// 	if(pid1 == 0)
// 		child_process(pipe_fd, av[1], av[2], ep);
// 	waitpid(pid1, &status, 0);
// 	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
// 	{
// 	// Child process exited with an error, so we should exit too.
// 		exit(WEXITSTATUS(status));
// 	}
// 	// sleep(2);
// 	parent_process(pipe_fd, av[4], av[3], ep);
// 	// sleep(3);
// 	return (0);
// }

void	child_process_1(int *pipe_fd, char *src_file, char *cmd1, char **ep)
{
	int	src_fd;

	close(pipe_fd[0]);
	src_fd = open(src_file, O_RDONLY);
	if (src_fd == -1)
	{
		perror("Failed to open source file");
		exit(EXIT_FAILURE);
	}
	if (dup2(src_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 failed.");
		close(src_fd);
		exit(EXIT_FAILURE);
	}
	close(src_fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed.");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[1]);
	run_command(cmd1, ep);
}

void	child_process_2(int *pipe_fd, char *dest_file, char *cmd2, char **ep)
{
	int dest_fd;

	close(pipe_fd[1]);
	dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (dest_fd == -1)
	{
		perror("Failed to open destination file");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 failed");
		close(dest_fd);
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	if (dup2(dest_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		close(dest_fd);
		exit(EXIT_FAILURE);
	}
	close(dest_fd);
	run_command(cmd2, ep);
}

int	main(int ac, char **av, char **ep)
{
	int pipe_fd[2];
	pid_t pid1;
	pid_t pid2;
	int status;

	if (ac != 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		exit(EXIT_FAILURE);
	}
	if (pipe(pipe_fd) == -1) {
		perror("pipe");
		return (EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == 0)
		child_process_1(pipe_fd, av[1], av[2], ep);
	pid2 = fork();
	if (pid2 == 0)
		child_process_2(pipe_fd, av[4], av[3], ep);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (0);
}


// int main(int argc, char *argv[], char **ep)
// {
// 	int result = the_real_main(argc, argv, ep);
// 	system("leaks pipex");
// 	return result;
// }
