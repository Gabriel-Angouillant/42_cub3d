/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:24:33 by augougea          #+#    #+#             */
/*   Updated: 2024/06/23 19:38:58 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static int	ft_find_len(char **file, int size, int index)
{
	int	tmp_len;
	int	len;
	int	i;

	i = index;
	len = 0;
	while (i++ < index + size)
	{
		tmp_len = ft_strrchr_i(file[i], ' ');
		if (tmp_len > len)
			len = tmp_len;
	}
	return (len);
}

static char	**ft_init_map(int size, char **file, int index)
{
	char	**tmp_map;
	int		i;
	int		len;

	i = -1;
	tmp_map = ft_calloc(sizeof(char *), size + 1);
	if (tmp_map == NULL)
		return (NULL);
	len = ft_find_len(file, size, index);
	while (i < size - 1)
	{
		index++;
		tmp_map[++i] = ft_strdup_len(file[index], len);
	}
	tmp_map[++i] = NULL;
	return (tmp_map);
}

char	*ft_charge_map(t_data *game)
{
	int	i;
	int	size;

	i = 5;
	size = i;
	while (game->file[++size])
		;
	size = size - i - 1;
	game->map = ft_init_map(size, game->file, i);
	if (game->map == NULL)
		return (ERR_LOAD_MAP);
	game->file = ft_free_array(game->file);
	close(game->fd);
	return (NULL);
}
