#include "../include/so_long.h"

void	press_w(t_data *data)
{
	char	c;
	
	c = data->map.map[data->py - 1][data->px];
	if (c == 'C')
		data->map.collect--;
	else if (c == 'S')
		ft_die(1);
	else if (c == 'E')
	{
		if (data->map.collect == 0)
			ft_goal(1);
		return ;
	}
	data->map.map[data->py - 1][data->px] = 'P';
	data->map.map[data->py][data->px] = 'z';
	if (data->py > 1)
		data->py--;
}

void	press_a(t_data *data)
{
	char	c;
	
	c = data->map.map[data->py][data->px - 1];
	if (c == 'C')
		data->map.collect--;
	else if (c == 'S')
		ft_die(1);
	else if (c == 'E')
	{
		if (data->map.collect == 0)
			ft_goal(1);
		return ;
	}
	data->map.map[data->py][data->px - 1] = 'p';
	data->map.map[data->py][data->px] = 'z';
	if (data->px > 1)
		data->px--;
}

void	press_s(t_data *data)
{
	char	c;
	
	c = data->map.map[data->py + 1][data->px];
	if (c =='C')
		data->map.collect--;
	else if (c == 'S')
		ft_die(1);
	else if (c == 'E')
	{
		if (data->map.collect == 0)
			ft_goal(1);
		return ;
	}	
	data->map.map[data->py + 1][data->px] = 'P';
	data->map.map[data->py][data->px] = 'z';
	if (data->py < data->map.map_height - 2)
		data->py++;
}

void	press_d(t_data *data)
{
	char	c;
	
	c = data->map.map[data->py][data->px + 1];
	if (c == 'C')
		data->map.collect--;
	else if (c == 'S')
		ft_die(1);
	else if (c == 'E')
	{
		if (data->map.collect == 0)
			ft_goal(1);
		return ;
	}
	data->map.map[data->py][data->px + 1] = 'P';
	data->map.map[data->py][data->px] = 'z';
	if (data->px < data->map.map_width - 2)
		data->px++;
}
