/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:49:42 by gangouil          #+#    #+#             */
/*   Updated: 2024/06/23 19:40:04 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static double	set_ray_dir(t_data *data, t_player *render, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)data->win.width_window - 1;
	render->ray_dir[X] = render->dir[X] + render->plane[X] * -camera_x;
	render->ray_dir[Y] = render->dir[Y] + render->plane[Y] * -camera_x;
	return (camera_x);
}

double	cast_ray(t_data *data, t_player *render)
{
	render->ray_pos[X] = (int)render->pos[X];
	render->ray_pos[Y] = (int)render->pos[Y];
	render->step_dist[X] = fabs(1 / render->ray_dir[X]);
	render->step_dist[Y] = fabs(1 / render->ray_dir[Y]);
	return (dda_calc(data->map, render));
}

void	render(t_data *data)
{
	int			x;
	double		res;
	t_player	*render;

	x = 0;
	render = &data->p;
	clear_window(&data->win, data->rgb_floor, data->rgb_sky);
	while (x < data->win.width_window)
	{
		set_ray_dir(data, render, x);
		if (x == data->win.width_window / 2)
		{
			texturing(render, &data->win, res, x);
			x++;
			continue ;
		}
		res = cast_ray(data, render);
		texturing(render, &data->win, res, x);
		x++;
	}
}
