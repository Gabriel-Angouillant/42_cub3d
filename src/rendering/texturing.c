/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 02:20:51 by gangouil          #+#    #+#             */
/*   Updated: 2024/06/23 19:08:14 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static int	get_texture_x(t_window *win, t_player *p, double wall_dist)
{
	double	wall_x;
	int		text_x;

	if (p->facing == X)
		wall_x = p->pos[Y] + wall_dist * p->ray_dir[Y];
	else
		wall_x = p->pos[X] + wall_dist * p->ray_dir[X];
	wall_x -= floor(wall_x);
	text_x = (int)(wall_x * win->pix[4]);
	if ((p->facing == X && p->ray_dir[X] > 0) || (p->facing == Y
			&& p->ray_dir[Y] < 0))
		text_x = win->pix[4] - text_x - 1;
	return (text_x);
}

static void	get_y_range(t_window *win, int line_height, int y_range[2])
{
	y_range[0] = -line_height / 2 + win->height_window / 2;
	y_range[1] = line_height / 2 + win->height_window / 2;
	if (y_range[0] < 0)
		y_range[0] = 0;
	if (y_range[1] >= win->height_window)
		y_range[1] = win->height_window - 1;
}

static void	paint_wall(t_window *win, t_player *p, int xy[2], double txy[2])
{
	if (p->facing == X && p->step_dir[X] == -1)
		mlx_pixel_put(win->mlx, win->win, xy[X], xy[Y],
			win->no_img[(int)txy[X]][(int)txy[Y] % win->pix[4]]);
	else if (p->facing == X && p->step_dir[X] == 1)
		mlx_pixel_put(win->mlx, win->win, xy[X], xy[Y],
			win->so_img[(int)txy[X]][(int)txy[Y] % win->pix[4]]);
	else if (p->facing == Y && p->step_dir[Y] == -1)
		mlx_pixel_put(win->mlx, win->win, xy[X], xy[Y],
			win->we_img[(int)txy[X]][(int)txy[Y] % win->pix[4]]);
	else
		mlx_pixel_put(win->mlx, win->win, xy[X], xy[Y],
			win->ea_img[(int)txy[X]][(int)txy[Y] % win->pix[4]]);
}

void	texturing(t_player *p, t_window *win, double wall_dist, int x)
{
	int		y_range[2];
	int		line_height;
	double	text_xy[2];
	double	y_step;

	win->pix[4] = get_texture_size(p, win->pix);
	text_xy[X] = get_texture_x(win, p, wall_dist);
	line_height = (int)(win->height_window / wall_dist);
	get_y_range(win, line_height, y_range);
	y_step = 1.0 * win->pix[4] / line_height;
	text_xy[Y] = (y_range[0] - win->height_window / 2 + line_height / 2)
		* y_step;
	while (y_range[0] <= y_range[1])
	{
		text_xy[Y] += y_step;
		paint_wall(win, p, (int [2]){x, y_range[0]}, text_xy);
		y_range[0]++;
	}
}
