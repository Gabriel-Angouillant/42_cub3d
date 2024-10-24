/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:16:36 by augougea          #+#    #+#             */
/*   Updated: 2024/06/23 19:42:11 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcub3D.h>

int	ft_check_extension(char *str, char *ext)
{
	int	len;
	int	len_ext;

	len_ext = ft_strlen(ext);
	len = ft_strlen_c(str, '\0') - len_ext;
	if (len < 0 || ft_strncmp(ext, &(*str) + len, len_ext) != 0)
		return (ERROR);
	return (SUCCESS);
}
