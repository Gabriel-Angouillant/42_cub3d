/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:50:26 by augougea          #+#    #+#             */
/*   Updated: 2023/11/02 22:51:28 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *memory, int searchedchar, size_t size)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) memory;
	i = 0;
	while (i < size)
	{
		if (str[i] == (unsigned char) searchedchar)
			return ((unsigned char *) &str[i]);
		i++;
	}
	return (NULL);
}
