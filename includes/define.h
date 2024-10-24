/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:04:57 by gangouil          #+#    #+#             */
/*   Updated: 2024/06/24 12:43:08 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:53:31 by augougea          #+#    #+#             */
/*   Updated: 2024/06/10 16:03:05 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define SUCCESS 0
# define ERROR 1
# define STDERR 2

# define BLANK_SPACE_N " \f\r\t\v\n"
# define BLANK_SPACE " \f\r\t\v"

# define LETTER_MAP "10NSEW"
# define NUMERIC_CHAR "0123456789"

# define ERR_ARG "Error : the number of args is wrong.\
 [./cub3D name_cart.cub]\n"
# define ERR_EXT "Error : the extension of the file is wrong. "
# define ERR_OPEN_FILE "Error : the file cannot be open. "
# define ERR_GNL "Error : a problem with get_next_line.\n"
# define ERR_MISSING "Error : missing. "
# define ERR_DUPLICATE "Error : duplication. "
# define ERR_MAP_MISSING "Error : map missing.\n"
# define ERR_INVALID_MAP "Error : format map invalid.\n"
# define ERR_SPLIT "Error : a problem with split.\n"
# define ERR_LOAD "Error : during download. "
# define ERR_LOAD_MAP "Error : during download map.\n"
# define ERR_PARSE_MAP "Error : a character is invalid.\n"
# define ERR_WALL "Error : a wall is invalid.\n"
# define ERR_INIT_PLAYER "Error : the player couldn't be initialised.\n"
# define ERR_ANY_PLAYER "Error : the player is not found.\n"
# define ERR_OUTSIDE_PLAYER "Error : the player is outside the map.\n"

#endif
