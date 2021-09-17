#include "../include/so_long.h"

void	window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->map.map_width * 32, data->map.map_height * 32, "so_long");
	put_image(data);
	mlx_hook(data->win,	KEYPRESS, 1L<<0, &move, data);
	mlx_loop(data->mlx);
}