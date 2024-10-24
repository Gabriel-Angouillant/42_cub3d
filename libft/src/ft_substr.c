/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:45:49 by augougea          #+#    #+#             */
/*   Updated: 2023/11/11 14:56:33 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t size)
{
	char	*str;
	char	*tmp;
	size_t	size_str;

	if (s == NULL)
		return (NULL);
	size_str = ft_strlen(s);
	if (start > size_str)
		size = 0;
	else if (size > (size_str - start))
		size = size_str - start;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	s = s + start;
	tmp = str;
	*(str + size) = '\0';
	while (size-- && *s != '\0')
		*str++ = *s++;
	return (tmp);
}
