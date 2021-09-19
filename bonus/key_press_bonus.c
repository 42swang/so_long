/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:32:26 by swang             #+#    #+#             */
/*   Updated: 2021/09/19 21:19:24 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	press_w(t_data *data)
{
	char	c;

	c = data->map.map[data->py - 1][data->px];
	if (c == 'C')
		data->map.collect--;
	else if (c == 'S')
		ft_die(++data->move);
	else if (c == 'E')
	{
		if (data->map.collect == 0)
			ft_goal(++data->move);
		return ;
	}
	data->map.map[data->py - 1][data->px] = 'P';
	data->map.map[data->py][data->px] = 'z';
	if (data->py > 1)
		data->py--;
	data->move++;
}

void	press_a(t_data *data)
{
	char	c;

	c = data->map.map[data->py][data->px - 1];
	if (c == 'C')
		data->map.collect--;
	else if (c == 'S')
		ft_die(++data->move);
	else if (c == 'E')
	{
		if (data->map.collect == 0)
			ft_goal(++data->move);
		return ;
	}
	data->map.map[data->py][data->px - 1] = 'p';
	data->map.map[data->py][data->px] = 'z';
	if (data->px > 1)
		data->px--;
	data->move++;
}

void	press_s(t_data *data)
{
	char	c;

	c = data->map.map[data->py + 1][data->px];
	if (c == 'C')
		data->map.collect--;
	else if (c == 'S')
		ft_die(++data->move);
	else if (c == 'E')
	{
		if (data->map.collect == 0)
			ft_goal(++data->move);
		return ;
	}	
	data->map.map[data->py + 1][data->px] = 'P';
	data->map.map[data->py][data->px] = 'z';
	if (data->py < data->map.map_height - 2)
		data->py++;
	data->move++;
}

void	press_d(t_data *data)
{
	char	c;

	c = data->map.map[data->py][data->px + 1];
	if (c == 'C')
		data->map.collect--;
	else if (c == 'S')
		ft_die(++data->move);
	else if (c == 'E')
	{
		if (data->map.collect == 0)
			ft_goal(++data->move);
		return ;
	}
	data->map.map[data->py][data->px + 1] = 'P';
	data->map.map[data->py][data->px] = 'z';
	if (data->px < data->map.map_width - 2)
		data->px++;
	data->move++;
}
