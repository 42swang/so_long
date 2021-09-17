/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:09:40 by swang             #+#    #+#             */
/*   Updated: 2021/09/18 02:14:46 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	put_image(t_data *data)
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
			mlx_put_image_to_window(data->mlx, data->win,
				data->image.floor, width * 32, height * 32);
		}
	}
}
