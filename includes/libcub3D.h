/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub3D.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:30:24 by augougea          #+#    #+#             */
/*   Updated: 2024/06/10 16:22:34 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB3D_H
# define LIBCUB3D_H

# include "define.h"
# include "include.h"
# include "structure.h"

/* CHARGE */
char	*ft_charge_map(t_data *game);
char	*ft_charge_paths_rgb(t_data *g);
int		ft_charge_rgb(char *cmp, char *str, t_rgb *rgb);
char	*ft_checks_all_access(t_data *game);
char	*ft_checks_all_paths_extension(t_data *game);

/* ERROR */
int		ft_put_exit_str(char *flag, int exit, char *str);
int		ft_put_exit(char *flag, int exit);

/* FREE */
char	*ft_free_inside_line(char *str, char *index);
int		ft_free_game(t_data *game, int flag);
void	free_img(int size, int **img);

/* GET_NEXT_LINE */
char	*get_next_line(int fd);

/* INIT */
char	*ft_init_fd(char *str, t_data *game);
char	*ft_init_file(t_data *game);
t_data	ft_init_game(void);

/* MAIN */
int		load_game(t_data *game, char *str);

/* PARSE */
char	*ft_parse_map(t_data *game);
int		ft_parse_format_path_rgb(char *str);
char	*ft_parse_format_map(char *str);
char	*ft_parse_player(t_data *game);

/* PROGRAM */
int		move_hook(int key, void *param);
int		window_hook(int event, void *param);
void	ft_close(t_window *win);
void	move_back(t_data *data);
void	move_front(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	rotate_right(t_data *data);
void	rotate_left(t_data *data);
void	start_game(t_data *game, t_window *win);

/* RENDERING */

double	dda_calc(char **map, t_player *render);
void	render(t_data *data);
void	texturing(t_player *p, t_window *win, double wall_dist, int x);

/* UTILS */
void	clear_window(t_window *win, t_rgb floor, t_rgb sky);
int		ft_check_access(char *str);
int		ft_check_extension(char *str, char *ext);
char	*ft_choose_search(int i);
void	ft_print(t_data *game);
int		ft_index_map(char *str);
int		ft_len_tab2d(char **tab2d);
void	ft_replace_char(char **map, char c, char replace);
char	*ft_str_to_find(char *str, char *to_find);
int		ft_str_to_find_i(char *str, char *to_find);
char	*ft_inv_str_to_find(char *str, char *to_find);
int		ft_inv_str_to_find_i(char *str, char *to_find);
int		get_texture_size(t_player *p, int pix[5]);
void	set_player_dir(t_data *data);

#endif