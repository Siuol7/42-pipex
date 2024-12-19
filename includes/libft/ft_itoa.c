/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:37:14 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:47:49 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_numlen(long long n)
{
	int	numlen;

	numlen = 0;
	while (n / 10 != 0)
	{
		numlen++;
		n /= 10;
	}
	if (n < 0)
		return (numlen + 2);
	return (numlen + 1);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			len;
	int			i;
	long long	nbr;

	nbr = n;
	i = 0;
	len = ft_numlen(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		res[0] = '-';
		i = 1;
	}
	res[len] = '\0';
	while (len > i)
	{
		res[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (res);
}
