/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:18:02 by swang             #+#    #+#             */
/*   Updated: 2021/09/17 17:11:01 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data data;
	
	if (argc == 2 && ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") == 0)//맵을 읽는 상황을 따로 정하고
	{	
		init_data(&data);
		open_map(&data, argv[1]);
		check_map(&data);
		find_player(&data);
		printf("m-col:%d exit:%d posit:%d\n", data.map.collect, data.map.exit, data.map.position);
		printf("m-map_width:%d map_height:%d\n", data.map.map_width, data.map.map_height);
		init_image(&data);
		window(&data);
	}
	else
		ft_error(NO_PRAM);
	return (0);
}