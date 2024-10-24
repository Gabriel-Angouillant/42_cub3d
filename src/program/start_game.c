/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:48:24 by gangouil          #+#    #+#             */
/*   Updated: 2024/06/23 19:42:46 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static void	*get_raw_img(t_data *data, char *img_path, int facing)
{
	void	*img;
	int		img_size[2];

	img = mlx_png_file_to_image(data->win.mlx, img_path, &img_size[0],
			&img_size[1]);
	if (!img)
		return (NULL);
	if (img_size[0] != img_size[1])
	{
		write(2, "Square textures only\n", 22);
		mlx_destroy_image(data->win.mlx, img);
		return (NULL);
	}
	data->win.pix[facing] = img_size[0];
	return (img);
}

static int	**img_to_array(t_data *data, char *img_path, int facing)
{
	int		**array;
	void	*img;
	int		x;
	int		y;

	x = 0;
	img = get_raw_img(data, img_path, facing);
	if (!img)
		return (NULL);
	array = ft_calloc(sizeof(int *), data->win.pix[facing]);
	while (array && x < data->win.pix[facing])
	{
		array[x] = ft_calloc(sizeof(int), data->win.pix[facing]);
		if (!array[x])
		{
			free_img(x, array);
			return (NULL);
		}
		y = -1;
		while (++y < data->win.pix[facing])
			array[x][y] = mlx_get_image_pixel(data->win.mlx, img, x, y);
		x++;
	}
	mlx_destroy_image(data->win.mlx, img);
	return (array);
}

static int	ft_init_win_img(t_data *game, t_window *win)
{
	win->mlx = mlx_init();
	mlx_set_fps_goal(win->mlx, 200);
	win->win = mlx_new_window(win->mlx, win->width_window, win->height_window,
			"cub3D");
	win->no_img = img_to_array(game, game->no_path, NORTH);
	win->so_img = img_to_array(game, game->so_path, SOUTH);
	win->we_img = img_to_array(game, game->we_path, WEST);
	win->ea_img = img_to_array(game, game->ea_path, EAST);
	if (!win->no_img || !win->so_img || !win->we_img || !win->ea_img)
		return (0);
	return (1);
}

void	start_game(t_data *game, t_window *win)
{
	if (!ft_init_win_img(game, win))
		return ;
	set_player_dir(game);
	render(game);
	mlx_on_event(win->mlx, win->win, MLX_WINDOW_EVENT, window_hook,
		(void *)game);
	mlx_on_event(win->mlx, win->win, MLX_KEYDOWN, move_hook, (void *)game);
	mlx_loop(win->mlx);
}
