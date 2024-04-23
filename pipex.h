/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:52:03 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/23 11:46:40 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
# include "libft/include/libft.h"

char *create_cmd_path(char *dir, char *cmd);
char *find_correct_path(char *cmd, char **ep);
void run_command(char *cmd, char **ep);
void	ft_free_split(char **arr);

#endif
