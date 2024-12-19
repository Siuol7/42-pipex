/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:53:46 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:41:14 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
	{
		ft_printf_fd(2, "pipex: Bad input arguments\n", 29);
		exit(1);
	}
	pipex.ac = ac;
	pipex.av = av;
	pipex.envp = envp;
	pipex.exit_status = 0;
	pipex.fork_times = 0;
	pipexshell(&pipex);
	exit(pipex.exit_status);
}
