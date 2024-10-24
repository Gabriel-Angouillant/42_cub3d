/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:51:37 by augougea          #+#    #+#             */
/*   Updated: 2024/06/10 16:21:57 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static int	ft_check_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_strchr(LETTER_MAP, str[i]) && !ft_strchr(BLANK_SPACE_N, str[i]))
			return (ERROR);
	}
	return (SUCCESS);
}

static int	ft_str_is_valid(char *str, int start, int end)
{
	while (ft_strchr(BLANK_SPACE, str[start]) && start < end)
		start++;
	if (ft_strchr(LETTER_MAP, str[start]))
		return (SUCCESS);
	return (ERROR);
}

static int	ft_check_valid_map(char *str)
{
	int		end;
	int		start;
	char	*tmp_str;
	int		len;

	len = ft_strlen(str);
	start = 0;
	while (str)
	{
		if (ft_strchr_i(&str[start], '\n') == -1)
			break ;
		end = start + ft_strchr_i(&str[start], '\n');
		if (ft_str_is_valid(str, start, end))
		{
			tmp_str = ft_str_to_find(&str[end], BLANK_SPACE_N);
			if (tmp_str[0] == 0)
				return (SUCCESS);
			else
				return (ERROR);
		}
		start = end + 1;
		if (start == len)
			break ;
	}
	return (SUCCESS);
}

static char	*ft_have_map(char *str)
{
	int		start;
	char	*tmp_str;

	start = ft_index_map(str);
	if (start == -1)
		return (NULL);
	tmp_str = ft_strchr(&str[start], '\n');
	if (tmp_str == NULL)
		return (NULL);
	tmp_str = ft_str_to_find(tmp_str, BLANK_SPACE_N);
	if (tmp_str[0] == '\0')
		return (NULL);
	return (tmp_str);
}

char	*ft_parse_format_map(char *str)
{
	char	*tmp_str;

	tmp_str = ft_have_map(str);
	if (tmp_str == NULL)
		return (ERR_MAP_MISSING);
	if (ft_check_valid_map(tmp_str))
		return (ERR_INVALID_MAP);
	if (ft_check_char(tmp_str))
		return (ERR_PARSE_MAP);
	return (NULL);
}
