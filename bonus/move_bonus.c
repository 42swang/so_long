/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:10:16 by swang             #+#    #+#             */
/*   Updated: 2021/09/19 20:34:39 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	move(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = data->px;
	y = data->py;
	if (keycode == 13 && data->map.map[y - 1][x] != '1')
		press_w(data);
	else if (keycode == 0 && data->map.map[y][x - 1] != '1')
		press_a(data);
	else if (keycode == 1 && data->map.map[y + 1][x] != '1')
		press_s(data);
	else if (keycode == 2 && data->map.map[y][x + 1] != '1')
		press_d(data);
	return (1);
}
