/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:48:24 by augougea          #+#    #+#             */
/*   Updated: 2024/06/23 19:36:15 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (str + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

int	ft_strstr_i(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_strstr_b(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strnstr_b(const char *str, const char *occurence, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_occ;

	i = 0;
	len_occ = ft_strlen(occurence);
	if (size == 0 && str == NULL)
		return (1);
	if (len_occ == 0 || occurence == str)
		return (1);
	while (str[i] != '\0' && i < size)
	{
		j = 0;
		while (str[i + j] != '\0' && occurence[j] != '\0' \
			&& str[i + j] == occurence[j] && i + j < size)
			j++;
		if (j == len_occ)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *str, const char *occurence, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_occ;

	i = 0;
	len_occ = ft_strlen(occurence);
	if (size == 0 && str == NULL)
		return (NULL);
	if (len_occ == 0 || occurence == str)
		return ((char *)str);
	while (str[i] != '\0' && i < size)
	{
		j = 0;
		while (str[i + j] != '\0' && occurence[j] != '\0' && \
			str[i + j] == occurence[j] && i + j < size)
			j++;
		if (j == len_occ)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
