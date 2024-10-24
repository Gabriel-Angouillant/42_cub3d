/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:02:36 by augougea          #+#    #+#             */
/*   Updated: 2023/11/04 16:03:39 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t size)
{
	if (size == 0)
		return (0);
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && size > 1)
	{
		s1++;
		s2++;
		size--;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
