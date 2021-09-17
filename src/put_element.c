/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:24:15 by swang             #+#    #+#             */
/*   Updated: 2021/09/18 02:18:09 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_spikes(t_data *data, int x, int y, int c)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->image.spikes, x * 32, y * 32);
	if (c != 0)
		data->map.map[y][x] = 'S';
	if (c == 'a')
		data->spk.a = 0;
	else if (c == 'b')
		data->spk.b = 0;
	else if (c == 'c')
		data->spk.c = 0;
	else if (c == 'd')
		data->spk.d = 0;
}

static void	spikes(t_data *data, int x, int y)
{
	int	w_half;
	int	h_half;

	w_half = data->map.map_width / 2;
	h_half = data->map.map_height / 2;
	if (w_half > x && h_half > y && data->spk.a == 1)
		put_spikes(data, x, y, 'a');
	else if (w_half < x && h_half > y && data->spk.b == 1)
		put_spikes(data, x, y, 'b');
	else if (w_half > x && h_half < y && data->spk.c == 1)
		put_spikes(data, x, y, 'c');
	else if (w_half < x && h_half < y && data->spk.d == 1)
		put_spikes(data, x, y, 'd');
}

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
			if (arr[y][x] == '0' && data->spk.s == 1)
				spikes(data, x, y);
			else if (arr[y][x] == 'S')
				put_spikes(data, x, y, 0);
			else if (arr[y][x] == 'E')
				put_door(data, x, y, data->map.collect);
			x++;
		}
		y++;
	}
	data->spk.s = 0;
}
