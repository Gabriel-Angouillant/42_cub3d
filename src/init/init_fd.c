/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:46:17 by augougea          #+#    #+#             */
/*   Updated: 2024/06/23 19:40:44 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

char	*ft_init_fd(char *str, t_data *game)
{
	int	fd;

	if (ft_check_extension(str, ".cub"))
		return (ERR_EXT);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ERR_OPEN_FILE);
	game->fd = fd;
	return (NULL);
}
