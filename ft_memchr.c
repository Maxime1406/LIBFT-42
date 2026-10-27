/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:07:40 by mbardeau          #+#    #+#             */
/*   Updated: 2026/10/27 16:51:49 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	i = 0;
	if (!s || !c)
		return (NULL);
	ptr = (const unsigned char *) s;
	while (i < n)
	{
		if (ptr[i] == (char)c)
			return ((char *)&ptr[i]);
		i++;
	}
	if ((char)c == '\0')
		return (NULL);
	return (NULL);
}


int	main(void)
{
	char *src = "/|\x12\xff\x09\x42\2002\42|\\";
	int	size = 10;
	printf("\nmemchr(): %s", (char *)memchr(src, '\200', size));
	printf("\nft_memchr(): %s", (char *)ft_memchr(src, '\200', size));
}