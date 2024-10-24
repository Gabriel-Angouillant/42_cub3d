/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:41:24 by augougea          #+#    #+#             */
/*   Updated: 2023/11/11 14:55:48 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t e_count, size_t e_size)
{
	unsigned char	*dest;
	size_t			m_size;
	size_t			i;

	i = 0;
	m_size = e_size * e_count;
	if (e_count != 0 && e_size != 0 && e_count > (4294967295 / m_size))
		return (NULL);
	dest = malloc(m_size);
	if (dest == NULL)
		return (NULL);
	while (i < m_size)
	{
		dest[i] = 0;
		i++;
	}
	return ((void *)dest);
}
