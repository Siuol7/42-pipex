/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:53:48 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/12 03:25:06 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../includes/libft/libft.h"
# include "../includes/ft_printf_fd/ft_printf.h"
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
	int				heredoc_sign;
	int				heredoc[2];
	int				fd[2];
	int				main_pipe[2];
	int				sub_pipe[2];
	int				exit_status;
	int				wait_status;
	int				fork_times;
	char			**av;
	char			**envp;
	pid_t			pid;
}		t_pipex;

//pipex_bonus.c
void	pipexshell(t_pipex *pipex);

//pipex_prexecve_bonus
void	file_open(t_pipex *pipex);
void	redirect(int in, int stdin, int out, int stdout);

//pipex_exec_bonus
void	cmd_exec(char *av, char **envp);

//pipex_utils_bonus
void	pipe_generating(int	*pipe);
void	redirect(int in, int stdin, int out, int stdout);
void	pipex_fork(t_pipex *pipex);
void	last_free(t_pipex *pipex, int *track);

//pipex_heredoc_bonus
void	read_heredoc(t_pipex *pipex);
char	*read_quote_dquote(char c);

//pipex_error_bonus
void	error_read(char *text, t_pipex *pipex);
void	error_envp(char **cmd);
void	error_open(t_pipex *pipex, int line);
void	error_read_quote_dquote(char *text);
void	error_isdir(char **cmd);

//pipex_check_bonus
int		path_envp_check(char **envp);
int		access_check(char **cmd);

//pipex_quote_dquote
char	*ft_quote_dquote(char *cmd, int	*track, int index);
int		ft_quote_dquote_len(char *string, char sign);
void	fill_quote_dquote(t_pipex *pipex, int *track);

//pipex_split_sh
char	**ft_split_sh(char *s, char c);
char	**ft_splitting(char **final, char *s, char c);
int		ft_wordlength(char *start, char c);
int		ft_quotelength(char *start, char c);

#endif