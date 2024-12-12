/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:53:46 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/13 01:09:37 by caonguye         ###   ########.fr       */
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
	//pipex.track = ft_calloc(ac, sizeof(int));
	//fill_quote_dquote(&pipex);
	pipexshell(&pipex);
	//last_free(&pipex);
	exit(pipex.exit_status);
}
