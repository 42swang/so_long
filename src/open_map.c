/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:23:17 by swang             #+#    #+#             */
/*   Updated: 2021/09/17 11:32:10 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_map_wall(int ret_gnl, char **line, int line_count)
{
	int	ret;
	char *str;

	ret = 1;
	str = *line;
	if (line_count == 1 || ret_gnl == 0)
	{
		ret = ft_check_long_wall(str);
		if (ret == 0)
		{
			free(*line);
			line = 0;
			ft_error(MAP_ERROR);
		}
	}
	else
	{
		ret = ft_check_short_wall(str);
		if (ret == 0)
		{
			free(*line);
			line = 0;
			ft_error(MAP_ERROR);
		}
	}
}
	
static void	check_map_obj(int ret_gnl, char **line, int line_count, t_data *data)
{
	int	ret;
	int	check_ret;
	char *str;

	ret = 1;
	check_ret = 0;
	str = *line;
	if (line_count == 1 || ret_gnl == 0)
		return ;
	else
	{
		check_ret = ft_check_obj(str, data);
		if (check_ret == -1)
		{	
			free(*line);
			line = 0;
			ft_error(MAP_ERROR);
		}
	}
}

static void	check_square(char **map_line, t_data *data)
{
	char	*str;
	int		i;

	i = 0;
	str = *map_line;
	if (data->count == -1)
	{
		while (str[i])
			i++;
		data->count = i;
		data->map.map_width = i;
	}
	else
	{
		while (str[i])
			i++;
		if (data->count != i)
		{
			free(*map_line);
			map_line = 0;
			ft_error(NOT_SQUARE);
		}
	}
}

int	open_map(t_data *data, char *av)
{
	char	*map_line;
	int	ret_gnl;
	int	line_count;

	ret_gnl = 1;
	line_count = 1;
	data->fd = open(av, O_RDONLY);
	if (data->fd < 0)
		ft_error(FD_ERROR);
	while (ret_gnl > 0)
	{
		ret_gnl = get_next_line(data->fd, &map_line);
		check_square(&map_line, data);
		check_map_wall(ret_gnl, &map_line, line_count);
		check_map_obj(ret_gnl, &map_line, line_count, data);
		line_count++;
	}
	data->map.map_height = line_count - 1;
	free(map_line);
	map_line = 0;
	close(data->fd);
	if (data->map.collect < 1 || data->map.exit < 1 || data->map.position < 1)
		return (0);
	return (1);
}