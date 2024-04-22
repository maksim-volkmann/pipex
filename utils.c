/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:33:08 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/22 13:33:43 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *create_cmd_path(char *dir, char *cmd)
{
	char *path;
	char *full_path;

	path = ft_strjoin(dir, "/");
	full_path = ft_strjoin(path, cmd);
	free(path);
	return full_path;
}

char *find_correct_path(char *cmd, char **ep)
{
	int		i;
	int		x;
	char	*path;
	char	**paths;
	char	*full_path;

	i = 0;
	while (ep[i]) {
		if (ft_strncmp(ep[i], "PATH=", 5) == 0)
		{
			path = ep[i] + 5;
			paths = ft_split(path, ':');
			x = 0;
			while (paths[x])
			{
				full_path = create_cmd_path(paths[x], cmd);
				if (access(full_path, X_OK) == 0)
				{
					free(paths);
					return full_path;
				}
				free(full_path);
				x++;
			}
			free(paths);
			break;
		}
		i++;
	}
	return NULL;
}

void run_command(char *cmd, char **ep)
{
	char **cmd_arr;
	char *executable_path;

	cmd_arr = ft_split(cmd, ' ');
	executable_path = find_correct_path(cmd_arr[0], ep);
	printf("executable_path: %s", executable_path);
}


