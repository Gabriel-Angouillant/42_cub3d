/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:57:05 by augougea          #+#    #+#             */
/*   Updated: 2023/11/04 17:04:47 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *memory, int octet, size_t size)
{
	unsigned char	*conv;

	conv = memory;
	while (size--)
	{
		*conv = (unsigned char) octet;
		conv++;
	}
	return (memory);
}
