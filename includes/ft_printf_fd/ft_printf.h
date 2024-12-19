/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:49:42 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:42:07 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

# define BUFFER_SIZE 1024

char	*ft_putchar_fd(int c);
char	*ft_putstr_fd(char *s);
char	*ft_base_check(int base, int low_up);
char	*ft_putnbr_base_fd(long long nbr, int baselen, int low_up);
int		ft_printf_fd(int fd, const char *format, ...);
char	*ft_printf_format_fd(char specifier, va_list ap);
char	*ft_print_address_fd(uintptr_t nbr, int baselen, int low_up);
char	*ft_strjoin_printf(char *s1, char *s2);
void	*ft_memcpy_printf(void *dest, void *src, size_t n);

#endif