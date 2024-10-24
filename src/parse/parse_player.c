/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:17:52 by augougea          #+#    #+#             */
/*   Updated: 2024/06/07 21:36:07 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static int	ft_pos_player(char c, int i, int j, t_player *player)
{
	if (ft_strchr("NSWE", c))
	{
		if (player->letter != 'X')
			return (ERROR);
		else
		{
			player->letter = c;
			player->pos[Y] = j + 0.5;
			player->pos[X] = i + 0.5;
		}
	}
	return (SUCCESS);
}

static int	ft_check_player(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i] != NULL)
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (ft_pos_player(game->map[i][j], i, j, &game->p))
				return (ERROR);
		}
	}
	return (SUCCESS);
}

char	*ft_parse_player(t_data *game)
{
	if (ft_check_player(game))
		return (ERR_INIT_PLAYER);
	if (game->p.letter == 'X')
		return (ERR_ANY_PLAYER);
	return (NULL);
}
