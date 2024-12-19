/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:15:12 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 19:48:09 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*newlst;
	t_list	*temp;

	newlst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&newlst, del);
			return (newlst);
		}
		ft_lstadd_back(&newlst, temp);
		lst = lst->next;
	}
	return (newlst);
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
// 	char	*y = ft_strdup("abcde  ");
// 	t_list *head = NULL;
// 	t_list *node1 = ft_lstnew((void *)x);
// 	t_list	*node2 = ft_lstnew((void *)y);
// 	t_list	*newlst = NULL;

// 	ft_lstadd_front(&head, node1);
// 	ft_lstadd_front(&head,node2);
// 	newlst = ft_lstmap(head, (void *)ft_strdup, (void *)del);
// 	ft_printlst(&newlst);
// 	ft_lstclear(&newlst, (void*)del);
// 	ft_lstclear(&head, (void *)del);
// 	return(0);
// }