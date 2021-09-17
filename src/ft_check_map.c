/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:36:57 by swang             #+#    #+#             */
/*   Updated: 2021/09/17 11:33:31 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_long_wall(char *str)
{
	while (*str)
	{
		if (*str != '1')
			return (0);
		str++;
	}
	return (1);
}

int	ft_check_short_wall(char *str)
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

int	ft_check_obj(char *str, t_data *data)
{
	int	check;
	int	i;

	check = 1;
	i = 0;
	while (str[i])
	{
	//	printf("%c\n", str[i]);
		if (str[i] == 'P')
			data->map.position += 1;
		else if (str[i] == 'E')
			data->map.exit += 1;
		else if (str[i] == 'C')
			data->map.collect += 1;
		else if (str[i] == '0' || str[i] == '1')
			check = 1;
		else
		{
			check = -1;
			return (check);
		}
		i++;
	}
	return (check);
}
