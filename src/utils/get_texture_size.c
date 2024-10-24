/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:17:17 by augougea          #+#    #+#             */
/*   Updated: 2024/06/23 19:42:21 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

int	get_texture_size(t_player *p, int pix[5])
{
	if (p->facing == X && p->step_dir[X] == -1)
		return (pix[NORTH]);
	else if (p->facing == X && p->step_dir[X] == 1)
		return (pix[SOUTH]);
	else if (p->facing == Y && p->step_dir[Y] == -1)
		return (pix[WEST]);
	else
		return (pix[EAST]);
}
