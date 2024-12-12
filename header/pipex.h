/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:53:48 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/12 05:10:15 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "includes/libft/libft.h"
# include "includes/ft_printf_fd/ft_printf.h"
# include <fcntl.h>
# include <sys/types.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>
# include <sys/stat.h>

# define BUFFER_SIZE 1024
# define SHELLCOLOR "\033[1m\033[37m"
# define RESET "\033[0m"

typedef struct s_pipex
{
	int				ac;
	int				fd[2];
	int				pipe[2];
	int				exit_status;
	int				wait_status;
	int				fork_times;
	char			**av;
	char			**envp;
	pid_t			pid;
}		t_pipex;

//pipex.c
void	pipexshell(t_pipex *pipex);

//pipex_utils
void	redirect(int in, int stdin, int out, int stdout);
void	last_free(t_pipex *pipex, int **track);

//pipex_exec
void	cmd_exec(char *av, char **envp);

//pipex_error
void	error_envp(char **cmd);
void	error_read_quote_dquote(char *text);
void	error_isdir(char **cmd);

//pipex_check
int		path_envp_check(char **envp);
int		access_check(char **cmd);

//pipex_quote_dquote
char	*ft_quote_dquote(char *cmd, int	*track, int index);
int		ft_quote_dquote_len(char *string, char sign);
void	fill_quote_dquote(t_pipex *pipex, int *track);

//pipex_read_quote_dquote
char	*read_quote_dquote(char c);

//pipex_split_sh
char	**ft_split_sh(char *s, char c);
void	ft_splitting(char **final, char *s, char c);
int		ft_wordlength(char *start, char c);
int		ft_quotelength(char *start, char c);

#endif