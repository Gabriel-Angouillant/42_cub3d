/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:28:04 by augougea          #+#    #+#             */
/*   Updated: 2024/06/23 19:41:28 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

char	*ft_str_to_find(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (ft_strchr(to_find, str[i]))
	{
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (&str[i]);
}

int	ft_str_to_find_i(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (ft_strchr(to_find, str[i]))
	{
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (i);
}

int	ft_inv_str_to_find_i(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (!ft_strchr(to_find, str[i]))
	{
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (i);
}

char	*ft_inv_str_to_find(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (!ft_strchr(to_find, str[i]))
	{
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (&str[i]);
}
