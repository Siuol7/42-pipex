/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:02:52 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/12 03:24:34 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex.h"

void	error_envp(char **cmd)
{
	ft_printf_fd(2, "pipex: line 82: %s: %s\n", *cmd, strerror(ENOENT));
	ft_free_2d((void **)cmd);
	exit(127);
}

void	error_read_quote_dquote(char *text)
{
	free(text);
	perror ("pipex: reading stdin failed: \n");
	exit(1);
}

void	error_isdir(char **cmd)
{
	ft_printf_fd(2, "pipex: line 77: %s: Is a directory\n", *cmd);
	ft_free_2d((void **)cmd);
	exit(126);
}
