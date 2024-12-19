/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:02:52 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/19 10:50:16 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	error_envp(char **cmd)
{
	ft_printf_fd(2, "pipex: %s: %s\n", *cmd, strerror(ENOENT));
	ft_free_2d((void **)cmd);
	exit(127);
}

void	error_isdir(char **cmd)
{
	ft_printf_fd(2, "pipex: %s: Is a directory\n", *cmd);
	ft_free_2d((void **)cmd);
	exit(126);
}
