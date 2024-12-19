/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_check_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:30:48 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:41:53 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_base_check(int baselen, int low_up)
{
	char	*binary;
	char	*octo;
	char	*decimal;
	char	*hexadecimal_lower;
	char	*hexadecimal_upper;

	binary = "01";
	octo = "01234567";
	decimal = "0123456789";
	hexadecimal_lower = "0123456789abcdef";
	hexadecimal_upper = "0123456789ABCDEF";
	if (baselen == 2)
		return (binary);
	else if (baselen == 8)
		return (octo);
	else if (baselen == 10)
		return (decimal);
	else if (baselen == 16 && low_up == 0)
		return (hexadecimal_lower);
	else if (baselen == 16 && low_up == 1)
		return (hexadecimal_upper);
	return (0);
}
