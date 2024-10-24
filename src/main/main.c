/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:28:10 by gangouil          #+#    #+#             */
/*   Updated: 2024/06/07 15:39:40 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

int	main(int argc, char **argv)
{
	t_data	game;

	(void)argv;
	if (argc != 2)
		return (ft_put_exit(ERR_ARG, STDERR));
	game = ft_init_game();
	if (load_game(&game, argv[1]))
		return (ft_free_game(&game, ERROR));
	start_game(&game, &game.win);
	return (ft_free_game(&game, SUCCESS));
}
