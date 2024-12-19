/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 23:20:00 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:42:43 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
// #include <stdio.h>

// int	main()
// {
// 	char	arrchar[6] = "abcde";
// 	int		arrint[6] = {1,2,3,4,5,6};

// 	ft_bzero(arrchar, 2);
// 	printf("Char %s\n", &arrchar[2]);
// 	ft_bzero(arrint, 12);
// 	for (int i = 0; i < 6; i++)
// 		printf("Int %d\n", arrint[i]);
// 	return (0);
// }