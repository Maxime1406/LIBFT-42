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

static size_t	ft_get_start(const char *s1, const char *set)
{
	size_t	i;
	size_t	start;

	start = 0;
	while (s1[start])
	{
		i = 0;
		while (set[i] && set[i] != s1[start])
			i++;
		if (!set[i])
			break;
		start++;
	}
	return (start);
}

static size_t	ft_get_end(const char *s1, const char *set, size_t start)
{
	size_t	i;
	size_t	end;

	end = ft_strlen(s1);
	if (end > 0)
		end--;
	while (end > start)
	{
		i = 0;
		while (set[i] && set[i] != s1[end])
			i++;
		if (!set[i])
			break;
		end--;
	}
	return (end);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*dest;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set, start);
	if (start > end)
		return (ft_strdup(""));
	len = end - start + 1;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, (char *)&s1[start], len + 1);
	return (dest);
}
