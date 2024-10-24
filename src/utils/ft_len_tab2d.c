/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_tab2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:19:05 by augougea          #+#    #+#             */
/*   Updated: 2024/06/23 19:42:29 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

int	ft_len_tab2d(char **tab2d)
{
	int	i;

	i = 0;
	if (!tab2d)
		return (i);
	while (tab2d[i])
		i++;
	return (i);
}
