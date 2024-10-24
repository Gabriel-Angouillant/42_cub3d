/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:50:30 by augougea          #+#    #+#             */
/*   Updated: 2023/11/04 17:04:04 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	size_t		i;
	size_t		j;
	char		*dest;
	char		*src;
	char		*tmp;

	dest = (char *)destination;
	src = (char *)source;
	tmp = src;
	i = 0;
	j = size - 1;
	if (destination > source)
	{
		while (i < size)
		{
			dest[j] = tmp[j];
			i++;
			j--;
		}
	}
	else
		dest = ft_memcpy(destination, source, size);
	return (destination);
}
