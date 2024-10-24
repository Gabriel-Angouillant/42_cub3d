/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:01:31 by gangouil          #+#    #+#             */
/*   Updated: 2024/06/10 16:07:49 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static int	ft_treat_fd(int fd, char **last_str)
{
	char	*tmp_str;

	tmp_str = get_next_line(fd);
	if (*last_str == NULL || tmp_str == NULL)
		return (ERROR);
	while (tmp_str != NULL)
	{
		*last_str = ft_strjoin_free(*last_str, tmp_str);
		free(tmp_str);
		if (*last_str == NULL)
			return (ERROR);
		tmp_str = get_next_line(fd);
	}
	free(tmp_str);
	if (*last_str == NULL)
		return (ERROR);
	return (SUCCESS);
}

static int	ft_split_line(char ***line, char *last_str)
{
	*line = ft_split(last_str, '\n');
	if (*line == NULL)
		return (ERROR);
	return (SUCCESS);
}

char	*ft_init_file(t_data *game)
{
	char	*last_str;
	char	*exit_code;

	last_str = ft_calloc(1, 1);
	if (ft_treat_fd(game->fd, &last_str))
		return (ft_free_inside_line(last_str, ERR_GNL));
	if (ft_parse_format_path_rgb(last_str))
		return (ft_free_inside_line(last_str, ""));
	exit_code = ft_parse_format_map(last_str);
	if (exit_code != NULL)
		return (ft_free_inside_line(last_str, exit_code));
	if (ft_split_line(&game->file, last_str))
		return (ft_free_inside_line(last_str, ERR_SPLIT));
	free(last_str);
	return (NULL);
}
