/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:24:15 by swang             #+#    #+#             */
/*   Updated: 2021/09/19 16:29:28 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_door(t_data *data, int x, int y, int item)
{
	if (item != 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->image.door, x * 32, y * 32);
	else if (item == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->image.stair, x * 32, y * 32);
}

static void	put_element2(t_data *data, int x, int y, int c)
{
	if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->image.player, x * 32, y * 32);
	else if (c == 'p')
		mlx_put_image_to_window(data->mlx, data->win,
			data->image.left_player, x * 32, y * 32);
	else if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->image.wall, x * 32, y * 32);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->image.item, x * 32, y * 32);
}

void	put_element(t_data *data)
{
	int		x;
	int		y;
	char	**arr;

	arr = data->map.map;
	y = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			if (arr[y][x] == 'P' || arr[y][x] == 'p'
				|| arr[y][x] == 'C' || arr[y][x] == '1')
				put_element2(data, x, y, arr[y][x]);
			else if (arr[y][x] == 'E')
				put_door(data, x, y, data->map.collect);
			x++;
		}
		y++;
	}
}
