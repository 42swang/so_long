/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:36:57 by swang             #+#    #+#             */
/*   Updated: 2021/09/17 14:36:08 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i != 0 && str[i] == '\n' && str[i - 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_square(t_data *data)
{
	int	i;
	char **arr;

	i = 0;
	arr = data->map.map;
	while (arr[i + 1])
	{
		if (ft_strlen(arr[i]) != ft_strlen(arr[i + 1]))
			return (0);
		i++;
	}
	data->map.map_width = ft_strlen(arr[0]);
	data->map.map_height = i + 1;
	return (1);
}

int	check_wall(t_data *data)
{
	int		i;
	int		ret;
	int		last;
	char	**arr;

	i = 0;
	ret = 1;
	last = data->map.map_height - 1;
	arr = data->map.map;
	while (arr[i])
	{
		if (i == 0 || i == last)
			ret = check_long_wall(arr[i]);
		else
			ret = check_short_wall(arr[i]);
		if (ret == 0)
				return (ret);
		i++;
	}
	return (1);
}

int	check_long_wall(char *str)
{
	while (*str)
	{
		if (*str != '1')
			return (0);
		str++;
	}
	return (1);
}

int	check_short_wall(char *str)
{
	if (*str != '1')
		return (0);
	while (*str)
		str++;
	str--;
	if (*str != '1')
		return (0);
	else
		return (1);
}
