/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:17:57 by swang             #+#    #+#             */
/*   Updated: 2021/09/17 11:26:12 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"

# define NO_PRAM 101
# define FD_ERROR 102
# define IMG_ERROR 103
# define MAP_ERROR 104
# define MLX_FAIL 105
# define NOT_SQUARE 106

typedef struct s_imgs
{
	void	*item;
	void	*player;
	void	*door_closed;
	void	*door;
	void	*wall;
	void	*floor;
	void	*spikes;
}			t_imgs;

typedef struct s_map
{
	int	position;
	int	collect;
	int	exit;
	int	map_width;
	int	map_height;
}	t_map;

typedef	struct s_spike
{
	int	a;
	int b;
	int c;
	int d;
}	t_spike;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		fd;
	int		count;
	char	*name;
	t_imgs	image;
	t_map	map;
	t_spike	spk;
}	t_data;

/* open map */
int	open_map(t_data *data, char *str);

/* ft_check map */
int	ft_check_long_wall(char *str);
int	ft_check_short_wall(char *str);
int	ft_check_obj(char *str, t_data *data);

/* init */
void	init_data(t_data *data);
void	init_image(t_data *data);

/* src */
void	window(t_data *data);
void	put_image(t_data *data);
void	put_floor(t_data *data);
void	put_element(t_data *data);
void	put_element2(int line, char *str, t_data *data);
void	put_spikes(t_data *data, int x, int y);
/* utils*/
int	ft_strcmp(char *s1, char *s2);
void	ft_error(int i);


#endif