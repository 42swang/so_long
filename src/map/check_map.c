/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:36:57 by swang             #+#    #+#             */
/*   Updated: 2021/08/31 16:36:15 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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

int	check_obj(char *str, t_map *info)
{
	int	check;

	check = 1;
	while (*str)
	{
		if (*str == 'P')
			info->position += 1;
		else if (*str == 'E')
			info->exit += 1;
		else if (*str == 'C')
			info->collect += 1;
		else if (*str == '0' || *str == '1')
			check = 1;
		else
		{
			check = -1;
			return (check);
		}
		str++;
	}
	return (check);
}