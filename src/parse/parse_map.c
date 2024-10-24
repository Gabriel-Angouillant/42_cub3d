/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:15:45 by augougea          #+#    #+#             */
/*   Updated: 2024/06/08 18:32:55 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static int	ft_check_pos(char **map, int y, int x, int len_map)
{
	if (x == 0 || y == 0 || y == len_map || x == (int)ft_strlen(map[y]) - 1)
		return (ERROR);
	if (x + 1 <= len_map && ft_strchr(" \0", map[x + 1][y]))
		return (ERROR);
	else if (y + 1 < (int)ft_strlen(map[x]) && ft_strchr(" \0", map[x][y + 1]))
		return (ERROR);
	else if (x - 1 >= 0 && ft_strchr(" \0", map[x - 1][y]))
		return (ERROR);
	else if (y - 1 >= 0 && ft_strchr(" \0", map[x][y - 1]))
		return (ERROR);
	return (SUCCESS);
}

static int	ft_fill(char **map, int y, int x, int len_map)
{
	if (y < 0 || x < 0 || y > len_map || x > (int)ft_strlen(map[y]) - 1)
		return (SUCCESS);
	if (map[y][x] == ' ')
	{
		map[y][x] = 'X';
		if (ft_fill(map, y, x + 1, len_map))
			return (ERROR);
		if (ft_fill(map, y, x - 1, len_map))
			return (ERROR);
		if (ft_fill(map, y + 1, x, len_map))
			return (ERROR);
		if (ft_fill(map, y - 1, x, len_map))
			return (ERROR);
	}
	else if (ft_strchr("0NSEW", map[y][x]))
		return (ERROR);
	return (SUCCESS);
}

static char	*ft_return_error(char c, char player)
{
	if (c == player)
		return (ERR_OUTSIDE_PLAYER);
	if (c == '0')
		return (ERR_WALL);
	return (NULL);
}

static char	*ft_check_letter(t_data *g, int y, int x, int len_map)
{
	if (g->map[y][x] == g->p.letter || g->map[y][x] == '0')
	{
		if (ft_check_pos(g->map, y, x, len_map))
			return (ft_return_error(g->map[y][x], g->p.letter));
	}
	else if (g->map[y][x] == ' ')
	{
		if (ft_fill(g->map, y, x, len_map))
			return (ERR_WALL);
	}
	return (NULL);
}

char	*ft_parse_map(t_data *g)
{
	char	*exit_code;
	int		x;
	int		y;
	int		len_map;

	y = -1;
	len_map = ft_len_tab2d(g->map) - 1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			if (x == 0 || y == 0 \
				|| y == len_map || x == (int)ft_strlen(g->map[y]) - 1)
			{
				exit_code = ft_check_letter(g, y, x, len_map);
				if (exit_code != NULL)
					return (exit_code);
			}
		}
	}
	return (NULL);
}
