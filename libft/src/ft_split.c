/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:58:23 by augougea          #+#    #+#             */
/*   Updated: 2023/11/11 14:59:42 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_words(char const *s, char sep)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != sep)
		{
			count++;
			while (*(s + i) && *(s + i) != sep)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	get_word_len(char const *s, char sep)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != sep)
		i++;
	return (i);
}

static void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
}

static char	**split(char const *s, char sep, char **array, size_t words)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (*(s + j) && *(s + j) == sep)
			j++;
		*(array + i) = ft_substr(s, j, get_word_len(&*(s + j), sep));
		if (*(array + i) == NULL)
		{
			free_array(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != sep)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char const *s, char separator)
{
	char	**array;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, separator);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (array == NULL)
		return (NULL);
	array = split(s, separator, array, words);
	return (array);
}
