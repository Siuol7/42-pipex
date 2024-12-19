/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:38:43 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:42:14 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digitcount(long long nbr, unsigned int baselen)
{
	int	cnt;

	cnt = 0;
	if (nbr < 0)
	{
		cnt += 2;
		nbr = -nbr;
	}
	else
		cnt += 1;
	while (nbr >= baselen)
	{
		nbr /= baselen;
		cnt++;
	}
	return (cnt);
}

static int	ft_hexacount(unsigned long long nbr, unsigned int baselen)
{
	int	cnt;

	cnt = 0;
	while (nbr >= baselen)
	{
		nbr /= baselen;
		cnt++;
	}
	return (cnt + 1);
}

static void	ft_puthexa(unsigned long long n, char *bs, int bl, char **w)
{
	if (n >= (unsigned long long)bl)
		ft_puthexa(n / bl, bs, bl, w);
	**w = bs[n % bl];
	(*w)++;
}

static void	ft_putnbr(long long nbr, char *base, int baselen, char **wrote)
{
	if (nbr < 0)
	{
		**wrote = '-';
		nbr = -nbr;
		(*wrote)++;
	}
	if (nbr >= baselen)
		ft_putnbr(nbr / baselen, base, baselen, wrote);
	**wrote = base[nbr % baselen];
	(*wrote)++;
}

char	*ft_putnbr_base_fd(long long nbr, int baselen, int low_up)
{
	char	*base;
	char	*wrote;
	char	*temp;

	if (baselen == 16)
		wrote = malloc(ft_hexacount(nbr, baselen) + 1);
	else
		wrote = malloc(ft_digitcount(nbr, baselen) + 1);
	if (!wrote)
		return (NULL);
	temp = wrote;
	base = ft_strdup(ft_base_check(baselen, low_up));
	if (baselen == 16)
		ft_puthexa(nbr, base, baselen, &temp);
	else
		ft_putnbr(nbr, base, baselen, &temp);
	*temp = '\0';
	free(base);
	return (wrote);
}
