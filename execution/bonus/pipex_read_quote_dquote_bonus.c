/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_read_quote_dquote_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 03:41:52 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/11 23:13:48 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex_bonus.h"

static char	*expand(char *text, int *i)
{
	char	*newtext;
	int		current_size;

	current_size = *i;
	newtext = ft_calloc(current_size + BUFFER_SIZE, 1);
	if (!newtext)
	{
		free(text);
		text = NULL;
		exit(1);
	}
	ft_memcpy(newtext, text, current_size);
	free (text);
	text = NULL;
	return (newtext);
}

static void	gnl_quote_dquote(char *text, char c, int *i, char *sign)
{
	char	word;
	int		readbytes;

	if (!text)
		exit(1);
	while (1)
	{
		readbytes = read(0, &word, 1);
		if (readbytes == -1)
			error_read_quote_dquote(text);
		text[(*i)++] = word;
		if (text[(*i) - 1] == c)
		{
			text[(*i)] = '\0';
			break ;
		}
		if (text[(*i) - 1] == '\n')
			ft_printf_fd(1, SHELLCOLOR"%s"RESET, sign);
		if (*i >= BUFFER_SIZE)
			text = expand(text, i);
	}
}

char	*read_quote_dquote(char c)
{
	char	*text;
	char	*sign;
	int		i;

	i = 0;
	text = ft_calloc(BUFFER_SIZE + 1, 1);
	if (c == '\'')
		sign = ft_strdup("quote>");
	else
		sign = ft_strdup("dquote>");
	ft_printf_fd(1, SHELLCOLOR"%s"RESET, sign);
	gnl_quote_dquote(text, c, &i, sign);
	free(sign);
	sign = NULL;
	return (text);
}
