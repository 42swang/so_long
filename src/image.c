#include "../include/so_long.h"

int		put_image(t_data *data)
{
	put_floor(data);
	put_element(data);
	return (1);
}

void	put_floor(t_data *data)
{
	int	width;
	int	height;

	height = data->map.map_height;
	while (height > 0)
	{
		height--;
		width = data->map.map_width;
		while (width > 0)
		{
			width--;
			mlx_put_image_to_window(data->mlx, data->win, data->image.floor, width * 32, height * 32);
		}
	}
}

static void	put_spikes(t_data *data, int x, int y)
{
	int	w_half;
	int h_half;

	w_half = data->map.map_width / 2;
	h_half = data->map.map_height / 2;
	if (w_half > x && h_half > y && data->spk.a == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image.spikes, x * 32, y * 32);
		data->map.map[y][x] = 'S';
		data->spk.a = 0;
	}
	else if (w_half < x && h_half > y && data->spk.b == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image.spikes, x * 32, y * 32);
		data->map.map[y][x] = 'S';
		data->spk.b = 0;
	}
	else if (w_half > x && h_half < y && data->spk.c == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image.spikes, x * 32, y * 32);
		data->map.map[y][x] = 'S';
		data->spk.c = 0;
	}
	else if (w_half < x && h_half < y && data->spk.d == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image.spikes, x * 32, y * 32);
		data->map.map[y][x] = 'S';
		data->spk.d = 0;
	}
}

void	put_element(t_data *data)
{
	int	x;
	int y;
	char	**arr;

	arr = data->map.map;
	y = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			if (arr[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->image.wall, x * 32, y * 32);
			else if (arr[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->image.item, x * 32, y * 32);
			else if (arr[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->image.player, x * 32, y * 32);
			else if (arr[y][x] == 'p')
				mlx_put_image_to_window(data->mlx, data->win, data->image.left_player, x * 32, y * 32);
			else if (arr[y][x] == 'E' && data->map.collect != 0)
				mlx_put_image_to_window(data->mlx, data->win, data->image.door, x * 32, y * 32);
			else if (arr[y][x] == 'E' && data->map.collect == 0)
				mlx_put_image_to_window(data->mlx, data->win, data->image.stair, x * 32, y * 32);
			else if (arr[y][x] == 'S')
				mlx_put_image_to_window(data->mlx, data->win, data->image.spikes, x * 32, y * 32);
			else if (arr[y][x] == '0' && data->spk.s == 1)
				put_spikes(data, x, y);
			x++;
		}
		y++;
	}
	data->spk.s = 0;
}
