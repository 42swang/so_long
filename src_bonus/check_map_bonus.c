/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:36:57 by swang             #+#    #+#             */
/*   Updated: 2021/09/19 20:33:59 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	check_nl_and_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != 'C' && str[i] != 'P'
			&& str[i] != 'E' && str[i] != '0' && str[i] != '\n')
			return (0);
		if (i != 0 && str[i] == '\n' && str[i - 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_square(t_data *data)
{
	int		i;
	char	**arr;

	i = 0;
	arr = data->map.map;
	while (arr[i + 1])
	{
		if (ft_strlen(arr[i]) != ft_strlen(arr[i + 1]))
			return (0);
		i++;
	}
	data->map.map_width = (int)ft_strlen(arr[0]);
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
