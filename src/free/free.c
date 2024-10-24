/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:58:08 by gangouil          #+#    #+#             */
/*   Updated: 2024/06/10 16:06:03 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:00:18 by gangouil          #+#    #+#             */
/*   Updated: 2024/05/26 16:47:56 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

void	free_img(int size, int **img)
{
	int	i;

	i = 0;
	if (!img)
		return ;
	while (i < size)
	{
		free(img[i]);
		i++;
	}
	free(img);
}

char	*ft_free_inside_line(char *str, char *index)
{
	if (str != NULL)
		free(str);
	return (index);
}

static t_data	*ft_free_inside_game(t_data *game)
{
	close(game->fd);
	if (game->file != NULL)
		game->file = ft_free_array(game->file);
	if (game->map != NULL)
		game->map = ft_free_array(game->map);
	if (game->no_path != NULL)
		free(game->no_path);
	if (game->so_path != NULL)
		free(game->so_path);
	if (game->ea_path != NULL)
		free(game->ea_path);
	if (game->we_path != NULL)
		free(game->we_path);
	return (NULL);
}

int	ft_free_game(t_data *game, int flag)
{
	if (game->win.win)
		mlx_destroy_window(game->win.mlx, game->win.win);
	if (game->win.mlx)
		mlx_destroy_display(game->win.mlx);
	free_img(game->win.pix[NORTH], game->win.no_img);
	free_img(game->win.pix[SOUTH], game->win.so_img);
	free_img(game->win.pix[WEST], game->win.we_img);
	free_img(game->win.pix[EAST], game->win.ea_img);
	game = ft_free_inside_game(game);
	return (flag);
}
