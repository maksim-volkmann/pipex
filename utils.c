/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:33:08 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/22 14:56:19 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



char	*create_cmd_path(char *dir, char *cmd)
{
	char	*path;
	char	*full_path;

	path = ft_strjoin(dir, "/");
	full_path = ft_strjoin(path, cmd);
	free(path);
	return full_path;
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
			return full_path;
		free(full_path);
		x++;
	}
	return NULL;
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
			// for(int i = 0; paths[i] != NULL; i++)
			// {
			// 	printf("Paths: %s\n", paths[i]);
			// }
			executable_path = check_command_in_paths(paths, cmd);
			free(paths);
			if (executable_path != NULL)
				return executable_path;
			break ;
		}
		i++;
	}
	return NULL;
}

void	run_command(char *cmd, char **ep)
{
	char **cmd_arr;
	char *executable_path;

	cmd_arr = ft_split(cmd, ' ');
	// printf("command: %s\n", cmd_arr[0]);
	executable_path = find_correct_path(cmd_arr[0], ep);
	if (executable_path == NULL)
	{
		printf("Command not found: %s\n", cmd_arr[0]);
		exit(EXIT_FAILURE);
	}

	// printf("executable_path: %s", executable_path);
	execve(executable_path, cmd_arr, ep);
	// if (executable_path)
	// {
	// 	execve(executable_path, cmd_arr, ep);
	// 	perror("execve failed");  // execve should not return on success
	// 	free(executable_path);  // Make sure to free the path after execve call
	// } else {
	// 	printf("Command not found: %s\n", cmd_arr[0]);
	// }
}
