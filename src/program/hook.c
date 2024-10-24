/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:43:01 by gangouil          #+#    #+#             */
/*   Updated: 2024/06/03 15:25:12 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

void	ft_close(t_window *win)
{
	mlx_loop_end(win->mlx);
}

int	window_hook(int event, void *param)
{
	if (event == 0)
		ft_close(&((t_data *)param)->win);
	return (0);
}

int	move_hook(int key, void *param)
{
	if (key == 79)
		rotate_right((t_data *)param);
	else if (key == 80)
		rotate_left((t_data *)param);
	else if (key == 7)
		move_right((t_data *)param);
	else if (key == 4)
		move_left((t_data *)param);
	else if (key == 26)
		move_front((t_data *)param);
	else if (key == 22)
		move_back((t_data *)param);
	else if (key == 41)
		ft_close(&((t_data *)param)->win);
	render((t_data *)param);
	return (0);
}
