/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:53:46 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/12 01:06:16 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		*track;

	if ((ac < 5) || ((ft_strcmp(av[1], "here_doc") == 0) && ac < 6))
	{
		ft_printf_fd(2, "pipex: Bad input arguments\n", 29);
		exit(1);
	}
	if (ft_strcmp(av[1], "here_doc") == 0)
		pipex.heredoc_sign = 1;
	else
		pipex.heredoc_sign = 0;
	pipex.ac = ac;
	pipex.av = av;
	pipex.envp = envp;
	pipex.exit_status = 0;
	pipex.fork_times = 0;
	track = ft_calloc(ac, sizeof(int));
	fill_quote_dquote(&pipex, track);
	pipexshell(&pipex);
	last_free(&pipex, track);
	exit(pipex.exit_status);
}
