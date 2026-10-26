/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:07:40 by mbardeau          #+#    #+#             */
/*   Updated: 2026/10/23 18:45:07 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (len == 0)
	{
		dest = malloc(1);
		dest[0] = '\0';
		return (dest);
	}
	if (len > len_s - start)
		len = len_s - start;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len && start < len_s + 1)
	{
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	printf("\nft_substr(): %s", ft_substr("hello", 0, 29));
	return (0);
}*/