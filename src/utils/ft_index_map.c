/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:12:09 by augougea          #+#    #+#             */
/*   Updated: 2024/06/10 16:22:18 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static int	ft_search_index_max(char *str, char index_max, char *search)
{
	int	tmp_str_index;

	tmp_str_index = ft_strstr_i(str, search);
	if (tmp_str_index == -1)
		return (-1);
	if (index_max < tmp_str_index)
		return (tmp_str_index);
	else
		return (index_max);
	return (-1);
}

int	ft_index_map(char *str)
{
	char	*tmp_str;
	int		index_max;
	int		i;

	index_max = -1;
	i = -1;
	while (++i < 6)
	{
		tmp_str = ft_choose_search(i);
		index_max = ft_search_index_max(str, index_max, tmp_str);
		if (index_max == -1)
			return (-1);
	}
	return (index_max);
}
