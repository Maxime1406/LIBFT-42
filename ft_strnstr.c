/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:07:40 by mbardeau          #+#    #+#             */
/*   Updated: 2026/10/23 11:52:41 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *) big);
	j = 0;
	while (j < len && big[j])
	{
		i = 0;
		while (j < len && little[i] && big[j] && little[i] == big[j])
		{
			i++;
			j++;
		}
		if (little[i] == '\0')
			return ((char *)&big[j - i]);
		j = j - i + 1;
	}
	return (0);
}
