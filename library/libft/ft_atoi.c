/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 04:28:47 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:42:39 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long long	res;
	size_t		i;
	int			sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		if (res * sign < (long long)INT_MIN)
			return (0);
		if (res * sign > (long long)INT_MAX)
			return (-1);
		i++;
	}
	return ((int)(res * sign));
}
// #include <stdio.h>

// int	main(void)
// {
// 	printf("Original : %s || New : %d\n", "  ++123abc", ft_atoi("  ++123abc"));
// 	printf("Original : %s || New : %d\n", "  +123abc", ft_atoi("  +123abc"));
// 	printf("Original : %s || New : %d\n", "  +-123abc", ft_atoi("  +-123abc"));
// 	printf("Original : %s || New : %d\n", "  --123abc", ft_atoi("  --123abc"));
// 	printf("Original : %s || New : %d\n", "  -123abc", ft_atoi("  -123abc"));
// 	printf("Original : %s || New : %d\n", "  123abc", ft_atoi("  123abc"));
// 	printf("Original : %s || New : %d\n", "", ft_atoi(""));
// 	printf("Original : %s || New : %d\n", " ", ft_atoi(" "));
// 	printf("Original : %s || New : %d\n", "  ++", ft_atoi("  ++"));
// 	printf("Original : %s || New : %d\n", "  abc", ft_atoi("  abc"));
// 	return (0);
// }