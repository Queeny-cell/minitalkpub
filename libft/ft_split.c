/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapodevi <mapodevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:20:33 by mapodevi          #+#    #+#             */
/*   Updated: 2025/07/05 15:33:39 by mapodevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	free_tab(char **split, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free (split[i]);
		i++;
	}
	free (split);
}

static	char	**ft_malloc_split(char const *s, int c, size_t *i, size_t *j)
{
	char	**split;

	*i = 0;
	*j = 0;
	if (!s)
		return (0);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = ft_malloc_split(s, c, &i, &j);
	if (!split)
		return (0);
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || !s[i]) && index >= 0)
		{
			split[j] = word_dup(s, index, i);
			if (!split[j])
				return (free_tab(split, j), NULL);
			index = -1;
			j++;
		}
		i++;
	}
	return (split[j] = 0, split);
}
