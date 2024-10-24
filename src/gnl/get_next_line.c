/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:35:42 by augougea          #+#    #+#             */
/*   Updated: 2024/06/23 19:39:46 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3D.h"

static char	*ft_read_file(int fd, char *rest)
{
	int		index;
	char	*tmp;

	if (rest == NULL)
		rest = ft_calloc(1, 1);
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	index = 1;
	while (index > 0)
	{
		index = read(fd, tmp, BUFFER_SIZE);
		if (index == -1)
		{
			if (rest != NULL)
				free(rest);
			free(tmp);
			return (NULL);
		}
		tmp[index] = '\0';
		rest = ft_strjoin_free(rest, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (rest);
}

static char	*ft_extract_line(char *rest)
{
	char	*tmp;
	int		size;
	int		index;

	index = 0;
	if (rest[index] == '\0')
		return (NULL);
	size = ft_strlen_c(rest, '\n') + 1;
	tmp = malloc((size + 1) * sizeof(char));
	tmp[size] = '\0';
	tmp[size - 1] = '\0';
	while (rest[index] != '\0' && rest[index] != '\n')
	{
		tmp[index] = rest[index];
		index++;
	}
	if (rest[index] == '\n')
		tmp[index] = '\n';
	return (tmp);
}

static char	*ft_extract_next(char *rest)
{
	char	*tmp;
	size_t	size;
	size_t	index;

	index = 0;
	if (rest == NULL)
		return (NULL);
	size = ft_strlen_c(rest, '\n');
	if (rest[size] == '\0')
	{
		free(rest);
		return (NULL);
	}
	tmp = ft_calloc((ft_strlen_c(rest, '\0') - size + 1), sizeof(char));
	while (rest[++size] != '\0')
		tmp[index++] = rest[size];
	free(rest);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_read_file(fd, rest);
	if (rest == NULL)
		return (NULL);
	str = ft_extract_line(rest);
	rest = ft_extract_next(rest);
	return (str);
}
