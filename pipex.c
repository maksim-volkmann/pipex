/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:04:05 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/29 11:51:26 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process_1(int *pipe_fd, char *src_file, char *cmd1, char **ep)
{
	int	src_fd;

	close(pipe_fd[0]);
	src_fd = open(src_file, O_RDONLY);
	if (src_fd == -1)
		clean_up("Error:", pipe_fd[1], -1);
	if (dup2(src_fd, STDIN_FILENO) == -1)
		clean_up("dup2 failed", pipe_fd[1], src_fd);
	close(src_fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		clean_up("dup2 failed", pipe_fd[1], -1);
	close(pipe_fd[1]);
	run_command(cmd1, ep);
}

void	child_process_2(int *pipe_fd, char *dest_file, char *cmd2, char **ep)
{
	int	dest_fd;

	close(pipe_fd[1]);
	dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (dest_fd == -1)
		clean_up("Failed to open destination file", pipe_fd[0], -1);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		clean_up("dup2 failed", pipe_fd[0], dest_fd);
	close(pipe_fd[0]);
	if (dup2(dest_fd, STDOUT_FILENO) == -1)
		clean_up("dup2 failed", dest_fd, 1);
	close(dest_fd);
	run_command(cmd2, ep);
}

int	main(int ac, char **av, char **ep)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	initial_setup(ac, pipe_fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		child_process_1(pipe_fd, av[1], av[2], ep);
		exit(EXIT_SUCCESS);
	}
	if (pid1 > 0)
	{
		pid2 = fork();
		if (pid2 == 0)
		{
			child_process_2(pipe_fd, av[4], av[3], ep);
			exit(EXIT_SUCCESS);
		}
	}
	if (pid1 > 0 && pid2 > 0)
		close_and_wait(pipe_fd, pid1, pid2);
	return (0);
}
