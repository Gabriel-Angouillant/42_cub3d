/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:54:25 by augougea          #+#    #+#             */
/*   Updated: 2023/11/10 11:55:44 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	if (s == NULL || fd == 0)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s1[i], fd);
		i++;
	}
}
