/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:39:08 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:42:02 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_free(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

static char	*ft_formatting_fd(va_list ap, const char *format)
{
	char	*final;
	char	*prewrote;
	char	*wrote;
	int		i;

	i = 0;
	prewrote = ft_strdup("");
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			wrote = ft_printf_format_fd(format[++i], ap);
		else
			wrote = ft_putchar_fd(format[i]);
		final = ft_strjoin_printf(prewrote, wrote);
		ft_free(prewrote);
		ft_free(wrote);
		prewrote = final;
		i++;
	}
	return (prewrote);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	ap;
	char	*total_char;
	int		wrote;

	wrote = 0;
	va_start(ap, format);
	total_char = ft_formatting_fd(ap, format);
	va_end(ap);
	wrote = write(fd, total_char, ft_strlen(total_char));
	ft_free(total_char);
	if (wrote == -1)
		return (-1);
	return (wrote);
}
