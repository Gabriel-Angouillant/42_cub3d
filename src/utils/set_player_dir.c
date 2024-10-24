/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:15:47 by augougea          #+#    #+#             */
/*   Updated: 2024/06/07 20:15:59 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

void	set_player_dir(t_data *data)
{
	if (data->p.letter == 'N')
	{
		data->p.dir[X] = -1;
		data->p.plane[Y] = -0.66;
	}
	else if (data->p.letter == 'S')
	{
		data->p.dir[X] = 1;
		data->p.plane[Y] = 0.66;
	}
	else if (data->p.letter == 'W')
	{
		data->p.dir[Y] = -1;
		data->p.plane[X] = 0.66;
	}
	else
	{
		data->p.dir[Y] = 1;
		data->p.plane[X] = -0.66;
	}
	data->map[(int)data->p.pos[X]][(int)data->p.pos[Y]] = '0';
}
