/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:04:28 by mbardeau          #+#    #+#             */
/*   Updated: 2026/10/26 10:04:28 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "libft.h"

static char	**ft_free_tab(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_count_words(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_dup_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	word = ft_calloc(end - start + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_fill_split(const char *str, char c, char **res)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (!str[i])
			break ;
		k = i;
		while (str[i] && str[i] != c)
			i++;
		res[j] = ft_dup_word(str, k, i);
		if (!res[j])
			return (ft_free_tab(res, j));
		j++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	char	**final_res;

	if (!str)
		return (NULL);
	res = ft_calloc(ft_count_words(str, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	final_res = ft_fill_split(str, c, res);
	return (final_res);
}
