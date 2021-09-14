/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:23:17 by swang             #+#    #+#             */
/*   Updated: 2021/09/14 17:59:22 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	map_wall(int ret_gnl, char *str, int line_count)
{
	int	ret;

	ret = 1;
	if (line_count == 1 || ret_gnl == 0)
	{
		ret = check_long_wall(str);
		if (ret == 0)
			ft_error(MAP_WALL_ERROR);
	}
	else
	{
		ret = check_short_wall(str);
		if (ret == 0)
			ft_error(MAP_WALL_ERROR);
	}
}
	
static void	map_obj(int ret_gnl, char *str, int line_count, t_data *data)
{
	int	ret;
	int	check_ret;
	ret = 1;
	if (line_count == 1 || ret_gnl == 0)
		data->map.map_width = ft_strlen(str);
	else
	{
		check_ret = check_obj(str, data);
		if (check_ret == -1)
			ft_error(MAP_ERROR);
	}
}

int	open_map(t_data *data, char *av)
{
	int fd;
	char	*map_line;
	int	ret_gnl;
	int	line_count;

	ret_gnl = 1;
	line_count = 1;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	while (ret_gnl > 0)
	{	
		ret_gnl = get_next_line(fd, &map_line);
		map_wall(ret_gnl, map_line, line_count);
		map_obj(ret_gnl, map_line, line_count, data);
		line_count++;
	}
	data->map.map_height = line_count - 1;
	if (data->map.position < 1 || data->map.collect < 1 || data->map.exit < 1)
		return (0);
	return (1);
}