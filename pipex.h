/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:52:03 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/29 11:53:12 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/include/libft.h"

// run_commands.c
char	*create_cmd_path(char *dir, char *cmd);
char	*check_command_in_paths(char **paths, char *cmd);
char	*find_correct_path(char *cmd, char **ep);
void	run_command(char *cmd, char **ep);

// utils.c
void	ft_free_split(char **arr);
void	clean_up(char *err_msg, int fd1, int fd2);
void	initial_setup(int ac, int *pipe_fd);
void	close_and_wait(int *pipe_fd, pid_t pid1, pid_t pid2);

#endif
