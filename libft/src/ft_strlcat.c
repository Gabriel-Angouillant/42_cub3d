/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:54:40 by augougea          #+#    #+#             */
/*   Updated: 2023/11/04 16:55:34 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size == 0 && (dst == NULL || src == NULL))
		return (0);
	i = 0;
	while (dst[i] && (i < size))
		i++;
	j = i;
	if (size <= i)
		return (i + ft_strlen(src));
	while (src[i - j] && i < (size - 1))
	{
		dst[i] = src[i - j];
		i++;
	}
	dst[i] = '\0';
	return (j + ft_strlen(src));
}
