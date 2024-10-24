/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:49:12 by augougea          #+#    #+#             */
/*   Updated: 2024/06/07 21:25:42 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int searchedchar)
{
	size_t	i;

	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == (unsigned char)searchedchar)
			return ((char *)&str[i]);
		i--;
	}
	if (str[i] == (unsigned char)searchedchar)
		return ((char *)&str[i]);
	return (NULL);
}

int	ft_strrchr_i(const char *str, int searchedchar)
{
	int	len;

	len = ft_strlen(str) - 1;
	while (len > 0)
	{
		if (str[len] != (unsigned char)searchedchar)
			return (len + 1);
		len--;
	}
	if (str[len] != (unsigned char)searchedchar)
		return (len + 1);
	return (0);
}
