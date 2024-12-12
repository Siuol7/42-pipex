/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 03:25:16 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/12 05:09:30 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex_bonus.h"

int	path_envp_check(char **envp)
{
	int	i;

	i = -1;
	if (!envp || !*envp)
		return (0);
	else
	{
		while (envp[++i])
		{
			if (ft_strnstr(envp[i], "PATH=", 5))
				return (1);
		}
	}
	return (0);
}

int	access_check(char **cmd)
{
	struct stat	stat_path;
	if (stat(*cmd, &stat_path) != -1)
	{
		if (S_ISDIR(stat_path.st_mode))
			error_isdir(cmd);
	}
	if (access(*cmd, F_OK) == 0)
	{
		if (access(*cmd, X_OK) == 0)
			return (0);
		else
			return (126);
	}
	return (127);
}
