/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:07:40 by mbardeau          #+#    #+#             */
/*   Updated: 2026/10/23 12:05:03 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	len_s1;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	dest = malloc((len_s1 - i - (len_s1 - ) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		if (set[j])
	}
	return (dest);
}
