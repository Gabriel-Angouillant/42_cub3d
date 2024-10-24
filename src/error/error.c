/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:01:43 by augougea          #+#    #+#             */
/*   Updated: 2024/06/24 12:43:33 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3D.h"

int	ft_put_exit(char *flag, int exit)
{
	ft_putstr_fd(flag, exit);
	return (ERROR);
}

int	ft_put_exit_str(char *flag, int exit, char *str)
{
	ft_putstr_fd(flag, exit);
	ft_putchar_fd('[', exit);
	ft_putstr_fd(str, exit);
	ft_putstr_fd("]\n", exit);
	return (ERROR);
}
