/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:28:45 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:49:38 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr_2d(char **big, const char *little, int len)
{
	int	i;

	i = 0;
	while (big[i])
	{
		if (ft_strnstr(big[i], little, len) != NULL)
			return (1);
		i++;
	}
	return (0);
}
