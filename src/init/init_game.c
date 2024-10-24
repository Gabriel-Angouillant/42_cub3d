/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:37:51 by gangouil          #+#    #+#             */
/*   Updated: 2024/06/10 16:05:46 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static t_rgb	ft_init_rgb(void)
{
	t_rgb	tmp_rgb;

	tmp_rgb.alpha = 0xff;
	tmp_rgb.blue = 0;
	tmp_rgb.green = 0;
	tmp_rgb.red = 0;
	return (tmp_rgb);
}

static t_window	ft_init_window(void)
{
	t_window	tmp_window;

	tmp_window = (t_window){0};
	tmp_window.width_window = 1000;
	tmp_window.height_window = 800;
	return (tmp_window);
}

static t_player	ft_init_player(void)
{
	t_player	tmp_player;

	tmp_player = (t_player){0};
	tmp_player.letter = 'X';
	tmp_player.pos[X] = -1;
	tmp_player.pos[Y] = -1;
	return (tmp_player);
}

t_data	ft_init_game(void)
{
	t_data	tmp_game;

	tmp_game = (t_data){0};
	tmp_game.rgb_floor = ft_init_rgb();
	tmp_game.rgb_sky = ft_init_rgb();
	tmp_game.win = ft_init_window();
	tmp_game.p = ft_init_player();
	return (tmp_game);
}
