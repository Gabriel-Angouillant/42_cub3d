/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:33:31 by augougea          #+#    #+#             */
/*   Updated: 2023/11/11 14:52:01 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_begin(char const *s1, char const *set, int begin)
{
	int	j;

	j = 0;
	while (s1[begin] != '\0' && set[j] != '\0')
	{
		if (s1[begin] == set[j])
		{
			begin++;
			j = 0;
		}
		else
			j++;
	}
	return (begin);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		begin;
	int		end;
	int		j;

	j = 0;
	begin = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	end = ft_strlen(s1);
	begin = ft_begin(s1, set, begin);
	while (end > 0 && j < 4)
	{
		if (s1[end] == set[j])
		{
			end--;
			j = 0;
		}
		else
			j++;
	}
	str = ft_substr(s1, begin, (end - begin + 1));
	return (str);
}
