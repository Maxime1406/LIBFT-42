/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:15:49 by mbardeau          #+#    #+#             */
/*   Updated: 2026/10/23 11:26:26 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int str)
{
	if ((str >= 9 && str <= 13) || str == 32)
		return (1);
	return (0);
}

static long long	ft_convert(const unsigned char *ptr, int neg, int i)
{
	long long	res;

	res = 0;
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		if (res > (LLONG_MAX - (ptr[i] - '0')) / 10)
		{
			if (neg == 1)
				return (-1);
			return (0);
		}
		res = res * 10 + (ptr[i] - '0');
		i++;
	}
	return (res * neg);
}

int	ft_atoi(const char *nptr)
{
	int					i;
	int					neg;
	long long			res;
	const unsigned char	*ptr;

	i = 0;
	res = 0;
	neg = 1;
	ptr = (const unsigned char *)nptr;
	while (ft_isspace(ptr[i]))
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			neg *= -1;
		i++;
	}
	return ((int)ft_convert(ptr, neg, i));
}
