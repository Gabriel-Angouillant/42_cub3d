/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:48:23 by gangouil          #+#    #+#             */
/*   Updated: 2024/06/24 13:55:41 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:38:54 by gangouil          #+#    #+#             */
/*   Updated: 2024/06/10 16:09:53 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

enum
{
	X,
	Y,
};

enum
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
};

enum
{
	I_NO,
	I_SO,
	I_WE,
	I_EA,
	I_F,
	I_C,
};

enum
{
	INIT_FILE,
	CHARGE_PATH_RGB,
	CHARGE_MAP,
	CHECKS_ALL_PATHS_EXTENSION,
	CHECKS_ALL_ACCESS,
	PARSE_PLAYER,
	PARSE_MAP,
	EMPTY,
};

typedef struct s_player
{
	char			letter;
	int				facing;
	double			pos[2];
	double			dir[2];
	double			ray_dir[2];
	int				ray_pos[2];
	double			step_dist[2];
	int				step_dir[2];
	double			plane[2];
}					t_player;

typedef struct s_window
{
	void			*mlx;
	void			*win;
	int				width_window;
	int				height_window;
	int				pix[5];
	int				**no_img;
	int				**so_img;
	int				**ea_img;
	int				**we_img;
}					t_window;

typedef union u_rgb
{
	struct
	{
		uint8_t		blue;
		uint8_t		green;
		uint8_t		red;
		uint8_t		alpha;
	};
	uint32_t	hex;
}					t_rgb;

typedef struct s_data
{
	int				fd;
	char			**file;
	char			*no_path;
	char			*so_path;
	char			*ea_path;
	char			*we_path;
	char			**map;
	t_rgb			rgb_floor;
	t_rgb			rgb_sky;
	t_player		p;
	t_window		win;
}					t_data;

#endif
