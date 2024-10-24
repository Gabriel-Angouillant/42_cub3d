/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:09:23 by augougea          #+#    #+#             */
/*   Updated: 2024/06/07 16:09:27 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

char	*ft_checks_all_access(t_data *game)
{
	if (ft_check_access(game->no_path))
		return (game->no_path);
	if (ft_check_access(game->so_path))
		return (game->so_path);
	if (ft_check_access(game->ea_path))
		return (game->ea_path);
	if (ft_check_access(game->we_path))
		return (game->we_path);
	return (NULL);
}

char	*ft_checks_all_paths_extension(t_data *game)
{
	if (ft_check_extension(game->no_path, ".png"))
		return (game->no_path);
	if (ft_check_extension(game->so_path, ".png"))
		return (game->so_path);
	if (ft_check_extension(game->ea_path, ".png"))
		return (game->ea_path);
	if (ft_check_extension(game->we_path, ".png"))
		return (game->we_path);
	return (NULL);
}
