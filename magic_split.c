/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:40:27 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/03 11:50:16 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (start > ft_strlen(s))
	{
		*result = '\0';
		return (result);
	}
	while (len > 0 && start < ft_strlen(s))
	{
		result[i] = s[start];
		i++;
		start++;
		len--;
	}
	result[i] = '\0';
	return (result);
}

static int	ft_countwords(const char *s, char c)
{
	int		n_words;
	int		i;

	i = 0;
	n_words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			n_words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (n_words);
}

static char	**ft_build_split(const char *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		start;
	int		length;

	i = -1;
	j = 0;
	start = -1;
	length = ft_strlen(s);
	split = (char **) malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!split || sizeof(split) == 0)
		return (NULL);
	while (++i <= length)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || i == length))
		{
			split[j++] = ft_substr(s, start, i - start);
			start = -1;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_build_split(s, c));
}
