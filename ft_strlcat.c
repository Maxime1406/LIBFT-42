/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:33:43 by mbardeau          #+#    #+#             */
/*   Updated: 2026/10/23 18:32:08 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//faut gerer quand size est -1 car ca donne 
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	if (!dst)
		len_dst = 0;
	else
		len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size >= len_dst && size - len_dst > 0)
	{
		while (i < size - len_dst - 1)
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
		return (len_dst + len_src);
	}
	return (len_src + size);
}

#include <bsd/string.h>
int	main(void)
{
	char	dst1[10] = "A big";
	char 	*src1 = "test";
	size_t	res1;
	size_t	res2;
	res1 = strlcat(dst1, src1, -1);
	res2 = ft_strlcat(dst1, src1, -1);
	printf("\nstrlcat(): %zu", res1);
	printf("\nft_strlcat(): %zu", res2);
}