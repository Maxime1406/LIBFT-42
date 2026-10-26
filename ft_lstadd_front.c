/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 16:53:59 by mbardeau          #+#    #+#             */
/*   Updated: 2026/10/26 17:03:57 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	*lst->content = new->content;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->content = content;
	return (lst);
}

int	main(void)
{
	char	*content;
	content = "Hello!";
	t_list *res = ft_lstnew(content);
	t_list	*new = ft_lstnew("Coucou!!");
	printf("\nResultat de ft_lstnew(): %s", (char *)res->content);
	ft_lstadd_front(&res, *new);
	printf("\nResultat de ft_lstadd_front(): %s", (char *)res->content);
}