/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:23:34 by gangouil          #+#    #+#             */
/*   Updated: 2024/06/03 15:24:43 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static double	get_first_length(t_player *render, int pos)
{
	double	first_length;

	if (render->ray_dir[pos] > 0)
	{
		render->step_dir[pos] = 1;
		first_length = (render->ray_pos[pos] + 1.0 - render->pos[pos])
			* render->step_dist[pos];
	}
	else
	{
		render->step_dir[pos] = -1;
		first_length = (render->pos[pos] - render->ray_pos[pos])
			* render->step_dist[pos];
	}
	return (first_length);
}

static double	set_new_length(t_player *render, double length, int facing)
{
	render->ray_pos[facing] += render->step_dir[facing];
	render->facing = facing;
	return (length + render->step_dist[facing]);
}

double	dda_calc(char **map, t_player *render)
{
	double	length[2];

	length[X] = get_first_length(render, X);
	length[Y] = get_first_length(render, Y);
	while (1)
	{
		if (length[X] > length[Y])
			length[Y] = set_new_length(render, length[Y], Y);
		else
			length[X] = set_new_length(render, length[X], X);
		if (map[render->ray_pos[X]][render->ray_pos[Y]] == '1')
			break ;
	}
	if (render->facing == X)
		return (length[X] - render->step_dist[X]);
	else
		return (length[Y] - render->step_dist[Y]);
}
