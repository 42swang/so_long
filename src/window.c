/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:10:26 by swang             #+#    #+#             */
/*   Updated: 2021/09/18 02:18:44 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	window(t_data *data)
{
	data->win = mlx_new_window(data->mlx,
			data->map.map_width * 32, data->map.map_height * 32, "so_long");
	put_image(data);
	mlx_hook(data->win, KEYPRESS, 0, &move, data);
	mlx_loop_hook(data->mlx, &put_image, data);
	mlx_loop(data->mlx);
}
