/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:57:31 by caonguye          #+#    #+#             */
/*   Updated: 2024/11/04 05:15:07 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
// #include <stdio.h>
// int	main()
// {
// 	char	x[5] = "abcd";
// 	char	y[6] = "abcde";
// 	t_list *head = NULL;
// 	t_list *node1 = ft_lstnew((void *)x);
// 	t_list	*node2 = ft_lstnew((void *)y);

// 	ft_lstadd_front(&head, node1);
// 	ft_lstadd_front(&head,node2);
// 	printf("%s\n", ft_lstlast(head)->content);
// 	return(0);
// }