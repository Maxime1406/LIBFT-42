/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:14:23 by mbardeau          #+#    #+#             */
/*   Updated: 2026/10/29 11:27:52 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	void				*res;

	if (!dest && !src)
		return (dest);
	if (dest < src)
	{
		res = ft_memcpy(dest, src, n);
		return (res);
	}
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	while (n--)
		d[n] = s[n];
	return (dest);
}
