/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:29:10 by augougea          #+#    #+#             */
/*   Updated: 2024/06/07 15:50:40 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

static int	ft_check_value(char *str, int len, uint8_t *rgb_color)
{
	int		tmp_rgb;
	char	*tmp_str;

	tmp_str = ft_strdup_len(str, len);
	if (tmp_str == NULL)
		return (ERROR);
	tmp_rgb = ft_atoi(tmp_str);
	if (tmp_rgb < 0 || tmp_rgb > 255)
	{
		free(tmp_str);
		return (ERROR);
	}
	*rgb_color = tmp_rgb;
	free(tmp_str);
	return (SUCCESS);
}

static char	*ft_convert_rgb(char *str, uint8_t *rgb_color)
{
	int	len;

	len = ft_str_to_find_i(str, NUMERIC_CHAR);
	if (len < 1 || len > 3)
		return (NULL);
	if (ft_check_value(str, len, rgb_color))
		return (NULL);
	return (&str[len]);
}

static char	*ft_charge_value(char *str, uint8_t *rgb_color, int flag)
{
	char	*tmp_str;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	tmp_str = ft_str_to_find(str, BLANK_SPACE_N);
	tmp_str = ft_convert_rgb(tmp_str, rgb_color);
	if (tmp_str == NULL)
		return (NULL);
	tmp_str = ft_str_to_find(tmp_str, BLANK_SPACE_N);
	if (flag)
	{
		if (tmp_str[0] == ',')
			return (&tmp_str[1]);
		else
			return (NULL);
	}
	return (tmp_str);
}

static int	ft_charge_all_values(char *file, t_rgb *rgb)
{
	char	*tmp_str;

	tmp_str = ft_charge_value(file, &rgb->red, 1);
	if (tmp_str == NULL)
		return (ERROR);
	tmp_str = ft_charge_value(tmp_str, &rgb->green, 1);
	if (tmp_str == NULL)
		return (ERROR);
	tmp_str = ft_charge_value(tmp_str, &rgb->blue, 0);
	if (tmp_str == NULL)
		return (ERROR);
	tmp_str = ft_str_to_find(tmp_str, BLANK_SPACE_N);
	if (tmp_str[0] != '\0')
		return (ERROR);
	return (SUCCESS);
}

int	ft_charge_rgb(char *cmp, char *str, t_rgb *rgb)
{
	int	i;

	i = 0;
	while (ft_strchr(BLANK_SPACE_N, str[i]))
		i++;
	if (!ft_strncmp(cmp, &str[i], ft_strlen(cmp)))
	{
		if (ft_charge_all_values(&str[i + 2], rgb))
			return (ERROR);
	}
	return (SUCCESS);
}
