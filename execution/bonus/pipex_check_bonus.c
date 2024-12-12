/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 03:25:16 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/11 01:11:17 by caonguye         ###   ########.fr       */
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
	if (access(*cmd, F_OK) == 0)
	{
		if (access(*cmd, X_OK) == 0)
			return (1);
		else
			return (126);
	}
	return (127);
}
