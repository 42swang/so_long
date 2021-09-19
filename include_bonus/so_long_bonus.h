/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:17:57 by swang             #+#    #+#             */
/*   Updated: 2021/09/19 20:14:22 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define NO_PRAM 101
# define FD_ERROR 102
# define IMG_ERROR 103
# define MLX_FAIL 105

# define NOT_SQUARE 106
# define WALL_GUARD 107
# define ELEMENT_ERROR 108
# define KEYPRESS 2

typedef struct s_imgs
{
	void	*item;
	void	*player;
	void	*left_player;
	void	*door;
	void	*stair;
	void	*wall;
	void	*floor;
	void	*spikes;
}			t_imgs;

typedef struct s_map
{
	char	**map;
	int		position;
	int		collect;
	int		exit;
	int		map_width;
	int		map_height;
}	t_map;

typedef struct s_spike
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	s;
}	t_spike;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		fd;
	int		px;
	int		py;
	int		move;
	t_imgs	image;
	t_map	map;
	t_spike	spk;
}	t_data;

/* map */
void	open_map(t_data *data, char *str);

/* check map */
void	check_map(t_data *data);
int		check_nl_and_char(char *str);
int		check_square(t_data *data);
int		check_wall(t_data *data);
int		check_long_wall(char *str);
int		check_short_wall(char *str);
int		check_element(t_data *data);

/* init */
void	init_data(t_data *data);
void	init_image(t_data *data);
void	init_map(t_data *data);
void	init_spk(t_data *data);
void	get_image(t_data *data);

/* window*/
void	window(t_data *data);

/* image */
int		put_image(t_data *data);
void	put_floor(t_data *data);
void	put_element(t_data *data);

/* move */
int		move(int keycode, t_data *data);

/* key_press */
void	press_w(t_data *data);
void	press_a(t_data *data);
void	press_s(t_data *data);
void	press_d(t_data *data);
void	press_x(t_data *data);

/* utils*/
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_substr(const char *s, unsigned int start, int len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

/* ft_end*/
void	ft_error(int i);
void	ft_goal(int move);
void	ft_die(int move);

#endif