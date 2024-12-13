/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:02:06 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/13 02:24:19 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex_bonus.h"

static char	**extract_envp(char **envp)
{
	char	*envp_path;
	char	**path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnenv(envp[i], "PATH=", 5))
			envp_path = ft_strnenv(envp[i], "PATH=", 5);
		i++;
	}
	if (envp_path == NULL)
	{
		ft_printf_fd(2, "pipex: Path not found\n");
		exit(127);
	}
	path = ft_split(envp_path, ':');
	if (path == NULL)
	{
		ft_printf_fd(2, "pipex: Path not found\n");
		exit(127);
	}
	return (path);
}

static char	*cmd_path_join(char **path, char **cmd)
{
	char	*cmd_path;
	int		i;
	char	*new_path;

	i = -1;
	while (path[++i])
	{
		cmd_path = ft_strjoin(path[i], "/");
		new_path = ft_strjoin(cmd_path, *cmd);
		free(cmd_path);
		cmd_path = new_path;
		if (access_check(&cmd_path) == 0)
		{
			ft_free_2d((void **)path);
			return (cmd_path);
		}
		free(cmd_path);
	}
	ft_printf_fd(2, "pipex: %s: command not found\n", *cmd);
	ft_free_2d((void **)path);
	ft_free_2d((void **)cmd);
	exit(127);
}

static char	*gnrt_cmd_path(char **cmd, char **envp)
{
	char	**path;
	char	*cmd_path;
	int		status;

	if (ft_strchr(*cmd, '/'))
	{
		if (access_check(cmd) == 0)
			return (*cmd);
		if (access_check(cmd) == 1)
			error_isdir(cmd);
		status = access_check(cmd);
		ft_printf_fd(2, "pipex: line 77: %s: %s\n", *cmd, strerror(errno));
		ft_free_2d((void **)cmd);
		exit(status);
	}
	else if (!envp || !envp[0] || ft_strnstr_2d(envp, "PATH", 4) == 0)
		error_envp(cmd);
	path = extract_envp(envp);
	cmd_path = cmd_path_join(path, cmd);
	if (cmd_path)
		return (cmd_path);
	ft_printf_fd(2, "pipex: line 87: %s: %s\n", *cmd, strerror(errno));
	ft_free_2d((void **)cmd);
	ft_free_2d((void **)path);
	exit(127);
}

void	cmd_exec(char *av, t_pipex *pipex)
{
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split_sh(av, ' ');
	if (cmd == NULL || !*cmd)
	{
		ft_printf_fd(2, "pipex: %s: command not found\n", av);
		ft_free_2d((void **)cmd);
		exit(127);
	}
	cmd_path = gnrt_cmd_path(cmd, pipex->envp);
	execve(cmd_path, cmd, pipex->envp);
	ft_printf_fd(2, "pipex: line 109: %s: %s\n", cmd_path, strerror(errno));
	free(cmd_path);
	ft_free_2d((void **)cmd);
	exit(126);
}
