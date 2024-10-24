/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:44:23 by augougea          #+#    #+#             */
/*   Updated: 2024/06/24 12:39:32 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

void	ft_declaration_function(char *(*function[8])(t_data *game))
{
	function[INIT_FILE] = ft_init_file;
	function[CHARGE_PATH_RGB] = ft_charge_paths_rgb;
	function[CHARGE_MAP] = ft_charge_map;
	function[CHECKS_ALL_PATHS_EXTENSION] = ft_checks_all_paths_extension;
	function[CHECKS_ALL_ACCESS] = ft_checks_all_access;
	function[PARSE_PLAYER] = ft_parse_player;
	function[PARSE_MAP] = ft_parse_map;
	function[EMPTY] = NULL;
}

int	ft_exit_message(int index, char *exit_code)
{
	if (index == INIT_FILE || index == CHARGE_MAP || index == PARSE_PLAYER
		|| index == PARSE_MAP)
		return (ft_put_exit(exit_code, STDERR));
	else if (index == CHARGE_PATH_RGB)
		return (ft_put_exit_str(ERR_LOAD, STDERR, exit_code));
	else if (index == CHECKS_ALL_PATHS_EXTENSION)
		return (ft_put_exit_str(ERR_EXT, STDERR, exit_code));
	else if (index == CHECKS_ALL_ACCESS)
		return (ft_put_exit_str(ERR_OPEN_FILE, STDERR, exit_code));
	return (SUCCESS);
}

int	load_game(t_data *game, char *str)
{
	char	*exit_code;
	char	*(*function[8])(t_data *game);
	int		i;

	i = -1;
	ft_declaration_function(function);
	exit_code = ft_init_fd(str, game);
	if (exit_code != NULL)
		return (ft_put_exit_str(exit_code, STDERR, str));
	while (*function[++i] != NULL)
	{
		exit_code = (*function[i])(game);
		if (exit_code != NULL)
			return (ft_exit_message(i, exit_code));
	}
	ft_replace_char(game->map, ' ', '1');
	ft_replace_char(game->map, 'X', ' ');
	return (SUCCESS);
}
