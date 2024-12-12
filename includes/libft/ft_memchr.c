/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 23:42:50 by caonguye          #+#    #+#             */
/*   Updated: 2024/11/04 03:05:58 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		val;
	char		*str;

	str = (char *)s;
	val = (char)c;
	i = -1;
	while (++i < n)
	{
		if (str[i] == val)
			return ((void *)&str[i]);
	}
	return (NULL);
}
