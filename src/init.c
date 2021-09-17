#include "../include/so_long.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == 0)
		ft_error(MLX_FAIL);
	data->win = 0;
	data->img = 0;
	data->fd = 0;
	data->px = 0;
	data->py = 0;

	data->map.position = 0;
	data->map.collect = 0;
	data->map.exit = 0;
	data->map.map_width = 0;
	data->map.map_height = 0;

	data->image.item = 0;
	data->image.player = 0;
	data->image.left_player = 0;
	data->image.door = 0;
	data->image.stair = 0;
	data->image.wall = 0;
	data->image.floor = 0;
	data->image.spikes = 0;

	init_spk(data);
}

void	init_spk(t_data *data)
{
	data->spk.a = 1;
	data->spk.b = 1;
	data->spk.c = 1;
	data->spk.d = 1;
	data->spk.s = 1;
}

void	init_image(t_data *data)
{
	int	img_width;
	int	img_height;

	data->image.floor = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", &img_width, &img_height);
	data->image.item = mlx_xpm_file_to_image(data->mlx, "./img/item.xpm", &img_width, &img_height);
	data->image.door = mlx_xpm_file_to_image(data->mlx, "./img/door.xpm", &img_width, &img_height);
	data->image.stair =  mlx_xpm_file_to_image(data->mlx, "./img/stair.xpm", &img_width, &img_height);
	data->image.player =  mlx_xpm_file_to_image(data->mlx, "./img/player.xpm", &img_width, &img_height);
	data->image.left_player = mlx_xpm_file_to_image(data->mlx, "./img/left_player.xpm", &img_width, &img_height);
	data->image.wall =  mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &img_width, &img_height);
	data->image.spikes = mlx_xpm_file_to_image(data->mlx, "./img/spikes.xpm", &img_width, &img_height);
	if (data->image.floor == 0 || data->image.item == 0
			|| data->image.door == 0 || data->image.stair == 0
			|| data->image.player == 0 || data->image.wall == 0
			|| data->image.spikes == 0)
		ft_error(IMG_ERROR);
}

void	find_player(t_data *data)
{
	int	y;
	int x;
	char	**arr;

	arr = data->map.map;
	y = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			if (arr[y][x] == 'P' || arr[y][x] == 'p')
			{
				data->px = x;
				data->py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}