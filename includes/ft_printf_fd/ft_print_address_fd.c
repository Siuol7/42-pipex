/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 05:52:33 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:41:59 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_address_fd(uintptr_t nbr, int baselen, int low_up)
{
	char	*first;
	char	*second;
	char	*wrote;

	if (nbr == 0)
		wrote = ft_strdup("(nil)");
	else
	{
		first = ft_strdup("0x");
		second = ft_putnbr_base_fd(nbr, baselen, low_up);
		wrote = ft_strjoin_printf(first, second);
		free(first);
		free(second);
	}
	return (wrote);
}
