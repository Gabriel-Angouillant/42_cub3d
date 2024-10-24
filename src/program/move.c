/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:36:56 by augougea          #+#    #+#             */
/*   Updated: 2024/06/23 19:43:06 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static void	move_calc(t_data *data, double tmp[2], double first[2])
{
	if (data->map[(int)tmp[X]][(int)first[Y]] == '0')
		data->p.pos[X] = tmp[X];
	if (data->map[(int)first[X]][(int)tmp[Y]] == '0')
		data->p.pos[Y] = tmp[Y];
	if (data->map[(int)tmp[X]][(int)tmp[Y]] == '1'
		&& (data->p.pos[X] != first[X] && data->p.pos[Y] != first[Y]))
	{
		data->p.pos[X] = first[X];
		data->p.pos[Y] = first[Y];
	}
}

void	move_right(t_data *data)
{
	double	first[2];
	double	tmp[2];

	first[X] = data->p.pos[X];
	first[Y] = data->p.pos[Y];
	tmp[X] = data->p.pos[X] + data->p.dir[Y] * 0.05;
	tmp[Y] = data->p.pos[Y] - data->p.dir[X] * 0.05;
	move_calc(data, tmp, first);
}

void	move_left(t_data *data)
{
	double	first[2];
	double	tmp[2];

	first[X] = data->p.pos[X];
	first[Y] = data->p.pos[Y];
	tmp[X] = data->p.pos[X] - data->p.dir[Y] * 0.05;
	tmp[Y] = data->p.pos[Y] + data->p.dir[X] * 0.05;
	move_calc(data, tmp, first);
}

void	move_front(t_data *data)
{
	double	first[2];
	double	tmp[2];

	first[X] = data->p.pos[X];
	first[Y] = data->p.pos[Y];
	tmp[X] = data->p.pos[X] + data->p.dir[X] * 0.05;
	tmp[Y] = data->p.pos[Y] + data->p.dir[Y] * 0.05;
	move_calc(data, tmp, first);
}

void	move_back(t_data *data)
{
	double	first[2];
	double	tmp[2];

	first[X] = data->p.pos[X];
	first[Y] = data->p.pos[Y];
	tmp[X] = data->p.pos[X] - data->p.dir[X] * 0.05;
	tmp[Y] = data->p.pos[Y] - data->p.dir[Y] * 0.05;
	move_calc(data, tmp, first);
}
