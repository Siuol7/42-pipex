/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:53:48 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/19 10:51:27 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../library/libft/libft.h"
# include "../library/ft_printf_fd/ft_printf.h"
# include <fcntl.h>
# include <sys/types.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>

typedef struct s_pipex
{
	int				ac;
	int				fd[2];
	int				pipe[2];
	int				exit_status;
	int				wait_status;
	int				fork_times;
	int				*track;
	char			**av;
	char			**envp;
	pid_t			pid;
}		t_pipex;

//pipex.c
void	pipexshell(t_pipex *pipex);

//pipex_utils
void	redirect(int in, int stdin, int out, int stdout);
void	pipex_fork(t_pipex *pipex, int *pipe);
void	pipex_wait(t_pipex *pipex);

//pipex_exec
void	cmd_exec(char *av, t_pipex *pipex);

//pipex_error
void	error_envp(char **cmd);
void	error_isdir(char **cmd);

//pipex_check
int		path_envp_check(char **envp);
int		access_check(char **cmd);

//pipex_quote_dquote
int		ft_quote_dquote_len(char *string, char sign);

//pipex_split_sh
char	**ft_split_sh(char *s, char c);
void	ft_splitting(char **final, char *s, char c);
int		ft_wordlength(char *start, char c);
int		ft_quotelength(char *start, char c);

#endif