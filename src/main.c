/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:18:02 by swang             #+#    #+#             */
/*   Updated: 2021/09/28 02:40:54 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	find_player(t_data *data)
{
	int		y;
	int		x;
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2 && ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") == 0)
	{	
		init_data(&data);
		open_map(&data, argv[1]);
		check_map(&data);
		find_player(&data);
		get_image(&data);
		window(&data);
	}
	else
		ft_error(CHECK_PRAM, 0);
	return (0);
}
