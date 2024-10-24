/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:36:16 by augougea          #+#    #+#             */
/*   Updated: 2024/06/23 19:44:36 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

void	rotate_right(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->p.dir[X];
	data->p.dir[X] = data->p.dir[X] * cos(-0.1) - data->p.dir[Y] * sin(-0.1);
	data->p.dir[Y] = olddirx * sin(-0.1) + data->p.dir[Y] * cos(-0.1);
	oldplanex = data->p.plane[X];
	data->p.plane[X] = data->p.plane[X] * cos(-0.1) - data->p.plane[Y]
		* sin(-0.1);
	data->p.plane[Y] = oldplanex * sin(-0.1) + data->p.plane[Y] * cos(-0.1);
}

void	rotate_left(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->p.dir[X];
	data->p.dir[X] = data->p.dir[X] * cos(0.1) - data->p.dir[Y] * sin(0.1);
	data->p.dir[Y] = olddirx * sin(0.1) + data->p.dir[Y] * cos(0.1);
	oldplanex = data->p.plane[X];
	data->p.plane[X] = data->p.plane[X] * cos(0.1) - data->p.plane[Y]
		* sin(0.1);
	data->p.plane[Y] = oldplanex * sin(0.1) + data->p.plane[Y] * cos(0.1);
}
