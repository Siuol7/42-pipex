/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 03:34:58 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:42:04 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_format_fd(char specifier, va_list ap)
{
	char	*wrote;

	if (specifier == 'c')
		wrote = ft_putchar_fd(va_arg(ap, int));
	else if (specifier == 's')
		wrote = ft_putstr_fd(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		wrote = ft_putnbr_base_fd(va_arg(ap, int), 10, 0);
	else if (specifier == 'u')
		wrote = ft_putnbr_base_fd((unsigned int)va_arg(ap, int), 10, 0);
	else if (specifier == 'x')
		wrote = ft_putnbr_base_fd(va_arg(ap, unsigned), 16, 0);
	else if (specifier == 'X')
		wrote = ft_putnbr_base_fd(va_arg(ap, unsigned), 16, 1);
	else if (specifier == 'p')
		wrote = ft_print_address_fd((uintptr_t)va_arg(ap, void *), 16, 0);
	else if (specifier == '%')
		wrote = ft_strdup("%");
	else
		wrote = (ft_strdup(&specifier));
	return (wrote);
}
