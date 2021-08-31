/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:18:02 by swang             #+#    #+#             */
/*   Updated: 2021/08/31 15:55:16 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	int	fd;
	t_map	*info;

	if (argc != 2)
		ft_error(-1);
	info = (t_map *)malloc(sizeof(t_map));
	if (!info)
		ft_error(-1);
	info->collect = 0;
	info->position = 0;
	info->exit = 0;
	fd = open(argv[1], O_RDONLY);
	open_map(fd, info);
	printf("col:%d exit:%d posit:%d\n", info->collect, info->exit, info->position);
	free(info);
	
	
	close(fd);
}