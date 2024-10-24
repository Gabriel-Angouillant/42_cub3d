/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:14:48 by augougea          #+#    #+#             */
/*   Updated: 2024/06/23 19:41:12 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

void	clear_window(t_window *win, t_rgb floor, t_rgb sky)
{
	int	i;
	int	j;
	int	sep;

	i = 0;
	sep = win->height_window / 2;
	while (i < win->width_window)
	{
		j = 0;
		while (j < win->height_window)
		{
			if (j < sep)
				mlx_pixel_put(win->mlx, win->win, i, j, sky.hex);
			else
				mlx_pixel_put(win->mlx, win->win, i, j, floor.hex);
			j++;
		}
		i++;
	}
}

char	*ft_choose_search(int i)
{
	if (i == I_NO)
		return ("NO");
	else if (i == I_SO)
		return ("SO");
	else if (i == I_WE)
		return ("WE");
	else if (i == I_EA)
		return ("EA");
	else if (i == I_F)
		return ("F");
	else if (i == I_C)
		return ("C");
	return (NULL);
}
