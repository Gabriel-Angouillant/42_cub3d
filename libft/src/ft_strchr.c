/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:15:42 by augougea          #+#    #+#             */
/*   Updated: 2024/06/08 15:51:36 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *str, int searchedchar)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)searchedchar)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)searchedchar)
		return ((char *)str + i);
	return (NULL);
}

int	ft_strchr_b(const char *str, int searchedchar)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)searchedchar)
			return (0);
		i++;
	}
	if (str[i] == (char)searchedchar)
		return (0);
	return (1);
}

int	ft_strchr_i(const char *str, int searchedchar)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)searchedchar)
			return (i);
		i++;
	}
	if (str[i] == (char)searchedchar)
		return (i);
	return (-1);
}
