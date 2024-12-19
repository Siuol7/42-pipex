/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:27:32 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:47:56 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = *lst;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
// #include <stdio.h>

// void	ft_printlst(t_list **head)
// {
// 	t_list	*temp;

// 	temp = *head;
// 	if (!*head)
// 		return ;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// }
// void	del(char *s)
// {
// 	free(s);
// }
// int	main()
// {
// 	char	*x = ft_strdup("abcd");
// 	char	*y = ft_strdup("abcde");
// 	t_list *head = NULL;
// 	t_list *node1 = ft_lstnew((void *)x);
// 	t_list	*node2 = ft_lstnew((void *)y);

// 	ft_lstadd_front(&head, node1);
// 	ft_lstadd_front(&head,node2);
// 	ft_lstclear(&head, (void *)del);
// 	ft_printlst(&head);
// 	return(0);
// }