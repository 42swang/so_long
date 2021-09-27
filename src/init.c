/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:09:49 by swang             #+#    #+#             */
/*   Updated: 2021/09/27 22:04:39 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == 0)
		ft_error(MLX_FAIL, 0);
	data->win = 0;
	data->img = 0;
	data->fd = 0;
	data->px = 0;
	data->py = 0;
	init_image(data);
	init_map(data);
}

void	init_image(t_data *data)
{
	data->image.item = 0;
	data->image.player = 0;
	data->image.left_player = 0;
	data->image.door = 0;
	data->image.stair = 0;
	data->image.wall = 0;
	data->image.floor = 0;
}

void	init_map(t_data *data)
{
	data->map.position = 0;
	data->map.collect = 0;
	data->map.exit = 0;
	data->map.map_width = 0;
	data->map.map_height = 0;
}

void	get_image(t_data *data)
{
	int	img_width;
	int	img_height;

	data->image.floor = mlx_xpm_file_to_image(data->mlx,
			"./img/floor.xpm", &img_width, &img_height);
	data->image.item = mlx_xpm_file_to_image(data->mlx,
			"./img/item.xpm", &img_width, &img_height);
	data->image.door = mlx_xpm_file_to_image(data->mlx,
			"./img/door.xpm", &img_width, &img_height);
	data->image.stair = mlx_xpm_file_to_image(data->mlx,
			"./img/stair.xpm", &img_width, &img_height);
	data->image.player = mlx_xpm_file_to_image(data->mlx,
			"./img/player.xpm", &img_width, &img_height);
	data->image.left_player = mlx_xpm_file_to_image(data->mlx,
			"./img/left_player.xpm", &img_width, &img_height);
	data->image.wall = mlx_xpm_file_to_image(data->mlx,
			"./img/wall.xpm", &img_width, &img_height);
	if (data->image.floor == 0 || data->image.item == 0
		|| data->image.door == 0 || data->image.stair == 0
		|| data->image.player == 0 || data->image.wall == 0)
		ft_error(IMG_ERROR, data);
}
