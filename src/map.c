/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:23:17 by swang             #+#    #+#             */
/*   Updated: 2021/09/28 16:29:16 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_element(t_data *data)
{
	int		x;
	int		y;
	char	**arr;

	y = 0;
	arr = data->map.map;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			if (arr[y][x] == 'C')
				data->map.collect++;
			else if (arr[y][x] == 'E')
				data->map.exit++;
			else if (arr[y][x] == 'P')
				data->map.position++;
			x++;
		}
		y++;
	}
	if (data->map.collect == 0 || data->map.exit == 0
		|| data->map.position != 1)
		return (0);
	return (1);
}

void	check_map(t_data *data)
{
	int	ret;

	ret = 1;
	ret = check_square(data);
	if (ret == 0)
		ft_error(MAP_ERROR, data);
	ret = check_wall(data);
	if (ret == 0)
		ft_error(MAP_ERROR, data);
	ret = check_element(data);
	if (ret == 0)
		ft_error(MAP_ERROR, data);
}

void	open_map(t_data *data, char *av)
{
	char	*str;
	char	buf[2];
	char	*tmp;
	int		ret;

	data->fd = open(av, O_RDONLY);
	if (data->fd < 0)
		ft_error(FD_ERROR, data);
	str = ft_strdup("");
	while (read(data->fd, buf, 1) > 0)
	{
		buf[1] = '\0';
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
	}
	ret = check_nl_and_char(str);
	if (ret == 0)
	{
		free(str);
		close(data->fd);
		ft_error(MAP_ERROR, data);
	}
	data->map.map = ft_split(str, '\n');
	free(str);
}
