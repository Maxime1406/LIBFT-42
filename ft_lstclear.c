/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:01:31 by mbardeau          #+#    #+#             */
/*   Updated: 2026/10/27 16:11:07 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_lst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		current_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = current_lst;
	}
}
