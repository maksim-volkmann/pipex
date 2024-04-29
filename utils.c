/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:33:08 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/29 10:20:10 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	*create_cmd_path(char *dir, char *cmd)
{
	char	*path;
	char	*full_path;

	path = ft_strjoin(dir, "/");
	full_path = ft_strjoin(path, cmd);
	free(path);
	return (full_path);
}

char	*check_command_in_paths(char **paths, char *cmd)
{
	char	*full_path;
	int		x;

	x = 0;
	while (paths[x])
	{
		full_path = create_cmd_path(paths[x], cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		x++;
	}
	return (NULL);
}

char	*find_correct_path(char *cmd, char **ep)
{
	int		i;
	char	*path;
	char	*executable_path;
	char	**paths;

	i = 0;
	while (ep[i])
	{
		if (ft_strncmp(ep[i], "PATH=", 5) == 0)
		{
			path = ep[i] + 5;
			paths = ft_split(path, ':');
			executable_path = check_command_in_paths(paths, cmd);
			ft_free_split(paths);
			if (executable_path != NULL)
				return (executable_path);
			break ;
		}
		i++;
	}
	return (NULL);
}

void	run_command(char *cmd, char **ep)
{
	char	**cmd_arr;
	char	*executable_path;

	cmd_arr = ft_split(cmd, ' ');
	if (ft_strchr(cmd_arr[0], '/') != NULL)
		executable_path = ft_strdup(cmd_arr[0]);
	else
	{
		executable_path = find_correct_path(cmd_arr[0], ep);
		if (executable_path == NULL)
		{
			perror("Command not found");
			free(executable_path);
			ft_free_split(cmd_arr);
			exit(EXIT_FAILURE);
		}
	}
	execve(executable_path, cmd_arr, ep);
	perror("execve failed");
	free(executable_path);
	ft_free_split(cmd_arr);
	exit(EXIT_FAILURE);
}

// ./pipex non_exist_input "cat /dev/random" "wc" dest.txt
// < src3.txt cat /dev/random | head -n 5 > dest2.txt
// ./pipex /dev/urandom cat "head -1" dest.txt
