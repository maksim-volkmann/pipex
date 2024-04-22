/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:33:08 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/22 10:57:35 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find_path(char **ep)
{
	int i;

	i = 0;
	while(ep[i])
	{
		if(ft_strncmp(ep[i], "PATH=", 5) == 0)
		{
			return (ep[i] + 5);
		}
		i++;
	}
	return (NULL);
}

char *run_command(char *cmd, char **ep)
{
	char	*path;
	char	**paths;
	int i = 0;

	path = find_path(ep);
	paths = ft_split(path, ':');
	// printf("PATH found: %s\n", path);
	while(paths[i])
	{
		printf("paths: %s\n", paths[i]);
		i++;
	}
	return (0);
}
