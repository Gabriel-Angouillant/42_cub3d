/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:31:46 by augougea          #+#    #+#             */
/*   Updated: 2024/06/01 18:26:49 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strcpy_c(char *dest, char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup_len(const char *src, int len)
{
	char	*src_cpy;
	int		i;

	i = -1;
	src_cpy = ft_calloc((len + 1), sizeof(char));
	if (src_cpy == NULL)
		return (NULL);
	while (++i < len)
		src_cpy[i] = 0;
	src_cpy = ft_strncpy(src_cpy, (char *)src, len);
	return (src_cpy);
}

char	*ft_strdup(const char *src)
{
	char	*src_cpy;

	src_cpy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (src_cpy == NULL)
		return (NULL);
	src_cpy = ft_strcpy(src_cpy, (char *)src);
	return (src_cpy);
}

char	*ft_strdup_c(const char *src, char c)
{
	char	*src_cpy;

	src_cpy = malloc(sizeof(char) * (ft_strlen_c(src, c) + 1));
	if (src_cpy == NULL)
		return (NULL);
	src_cpy = ft_strcpy_c(src_cpy, (char *)src, c);
	return (src_cpy);
}
