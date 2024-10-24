/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:51:24 by augougea          #+#    #+#             */
/*   Updated: 2024/06/10 16:22:47 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static char	*ft_check_just_one(char *str, char *search)
{
	int		len_search;
	char	*tmp_str;

	len_search = ft_strlen(search);
	if (ft_strstr_b(str, search))
		return (ERR_MISSING);
	else
	{
		tmp_str = ft_strstr(str, search);
		if (ft_strchr_b(BLANK_SPACE_N, tmp_str[len_search]))
			return (ERR_MISSING);
		if (!ft_strstr_b(&tmp_str[len_search], search))
			return (ERR_DUPLICATE);
	}
	return (NULL);
}

int	ft_parse_format_path_rgb(char *str)
{
	char	*exit_code;
	char	*tmp_str;
	int		i;

	(void)exit_code;
	i = -1;
	while (++i < 6)
	{
		tmp_str = ft_choose_search(i);
		exit_code = ft_check_just_one(str, tmp_str);
		if (exit_code != NULL)
			return (ft_put_exit_str(exit_code, STDERR, tmp_str));
	}
	return (SUCCESS);
}
