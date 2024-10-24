/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:48:03 by augougea          #+#    #+#             */
/*   Updated: 2023/11/11 15:02:20 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_getlen(int n)
{
	int	power;

	if (n <= 0)
		power = 1;
	else
		power = 0;
	while (n != 0)
	{
		power++;
		n = n / 10;
	}
	return (power);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				nb_len;
	int				sign;
	char			*str;

	if (n >= 0)
		sign = 1;
	else
		sign = -1;
	nb = n * sign;
	nb_len = ft_getlen(n);
	str = (char *)ft_calloc(nb_len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	str[nb_len--] = '\0';
	while (nb_len >= 0)
	{
		str[nb_len--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}
