/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:23:17 by swang             #+#    #+#             */
/*   Updated: 2021/08/31 15:56:44 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	map_wall(int ret_gnl, char *str, int line_count)
{
	int	ret;

	ret = 1;
	if (line_count == 1 || ret_gnl == 0)
	{
		ret = check_long_wall(str);
		if (ret == 0)
			ft_error(MAP_ERROR);
	}
	else
	{
		ret = check_short_wall(str);
		if (ret == 0)
			ft_error(MAP_ERROR);
	}
}
	
static void	map_obj(int ret_gnl, char *str, int line_count, t_map *info)
{
	int	ret;
	int	check_ret;
	ret = 1;
	if (line_count == 1 || ret_gnl == 0)
		return ;
	else
	{
		check_ret = check_obj(str, info);
		if (check_ret == -1)
			ft_error(MAP_ERROR);
	}
}

void	open_map(int fd, t_map *info)
{
	char	*map_line;
	int	ret_gnl;
	int	line_count;

	ret_gnl = 1;
	line_count = 1;
	while (ret_gnl > 0)
	{	
		ret_gnl = get_next_line(fd, &map_line);
		map_wall(ret_gnl, map_line, line_count);
		map_obj(ret_gnl, map_line, line_count, info);
		line_count++;
	}
	map_wall(ret_gnl, map_line, line_count);
}