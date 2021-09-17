#include "../include/so_long.h"

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