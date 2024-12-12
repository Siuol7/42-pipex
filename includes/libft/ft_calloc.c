/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:25:18 by caonguye          #+#    #+#             */
/*   Updated: 2024/11/04 03:53:16 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb * size == 0)
		return (malloc(0));
	if (nmemb != (nmemb * size / size))
		return (NULL);
	res = malloc(size * nmemb);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}
