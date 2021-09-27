/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:05:53 by swang             #+#    #+#             */
/*   Updated: 2021/09/28 02:32:51 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = 0;
		i++;
	}
	free(str);
	return (0);
}

void	ft_destroy(t_data *data)
{
	if (data->map.map != 0)
		ft_free(data->map.map);
	if (data->win != 0)
		mlx_destroy_window(data->mlx, data->win);
	if (data->image.door != 0)
		mlx_destroy_image(data->mlx, data->image.door);
	if (data->image.floor != 0)
		mlx_destroy_image(data->mlx, data->image.floor);
	if (data->image.item != 0)
		mlx_destroy_image(data->mlx, data->image.item);
	if (data->image.left_player != 0)
		mlx_destroy_image(data->mlx, data->image.left_player);
	if (data->image.player != 0)
		mlx_destroy_image(data->mlx, data->image.player);
	if (data->image.stair != 0)
		mlx_destroy_image(data->mlx, data->image.stair);
	if (data->image.wall != 0)
		mlx_destroy_image(data->mlx, data->image.wall);
	exit(0);
}

int	ft_close(t_data *data)
{
	write(1, "click red cross button\n", 23);
	ft_destroy(data);
	return (0);
}

void	ft_error(int i, t_data *data)
{
	if (i == CHECK_PRAM)
		write(1, "check prameter\n", 15);
	else if (i == FD_ERROR)
		write(1, "map file fd error\n", 9);
	else if (i == MAP_ERROR)
		write(1, "check map condition\n", 20);
	else if (i == MLX_FAIL)
		write(1, "failed to conect window\n", 24);
	else if (i == IMG_ERROR)
		write(1, "failed to road image\n", 21);
	write(2, "Error\n", 7);
	ft_destroy(data);
}

void	ft_goal(int move, t_data *data)
{
	char	*ptr;

	ptr = ft_itoa(move);
	write(1, "movement:", 9);
	write(1, ptr, ft_strlen(ptr));
	write(1, "\n", 1);
	write(1, "Good\n", 5);
	free(ptr);
	ptr = 0;
	ft_destroy(data);
}
