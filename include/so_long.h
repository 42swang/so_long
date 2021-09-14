/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:17:57 by swang             #+#    #+#             */
/*   Updated: 2021/09/14 16:36:23 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"

# define MAP_WALL_ERROR 103
# define MAP_ERROR 104
# define INFO_COUNT 105

typedef struct s_map
{
	int	position;
	int	collect;
	int	exit;
	int	map_width;
	int	map_height;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	t_map	map;
}	t_data;

/* open map */
int	open_map(t_data *data, char *str);

/* check map */
int	check_long_wall(char *str);
int	check_short_wall(char *str);
int	check_obj(char *str, t_data *data);

/* src */
void	init_data(t_data *data);
void	ft_error(int e);
int	ft_strcmp(char *s1, char *s2);

#endif