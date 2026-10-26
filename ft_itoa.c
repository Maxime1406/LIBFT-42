/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:18:27 by mbardeau          #+#    #+#             */
/*   Updated: 2026/10/26 13:18:27 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "libft.h"

static int	ft_nbrlen(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len++;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dest;
	long	nbr;
	int		len;

	nbr = n;
	len = ft_nbrlen(nbr);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[len--] = '\0';
	if (nbr == 0)
		dest[0] = nbr + '0';
	if (nbr < 0)
	{
		dest[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		dest[len--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (dest);
}
