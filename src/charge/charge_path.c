/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:17:47 by gangouil          #+#    #+#             */
/*   Updated: 2024/06/24 12:38:44 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static int	ft_charge_path_img(char *str, char *file, char **dest)
{
	int	i;

	i = 0;
	while (ft_strchr(BLANK_SPACE_N, file[i]))
		i++;
	if (!ft_strncmp(str, &file[i], ft_strlen(str)))
	{
		i = i + ft_strlen(str);
		if (*dest != NULL)
			return (ERROR);
		while (ft_strchr(BLANK_SPACE_N, file[i]))
			i++;
		*dest = ft_strdup_len(&file[i], ft_inv_str_to_find_i(&file[i],
					BLANK_SPACE));
		if (*dest == NULL)
			return (ERROR);
	}
	return (SUCCESS);
}

char	*ft_charge_paths_rgb(t_data *g)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (ft_charge_path_img("NO", g->file[i], &g->no_path))
			return ("NO");
		else if (ft_charge_path_img("SO", g->file[i], &g->so_path))
			return ("SO");
		else if (ft_charge_path_img("WE", g->file[i], &g->we_path))
			return ("WE");
		else if (ft_charge_path_img("EA", g->file[i], &g->ea_path))
			return ("EA");
		else if (ft_charge_rgb("F", g->file[i], &g->rgb_floor))
			return ("F");
		else if (ft_charge_rgb("C", g->file[i], &g->rgb_sky))
			return ("C");
	}
	return (SUCCESS);
}
