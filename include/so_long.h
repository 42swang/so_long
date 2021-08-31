/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:17:57 by swang             #+#    #+#             */
/*   Updated: 2021/08/31 15:57:37 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>

# define MAP_ERROR 100

typedef struct s_map
{
	int	position;
	int	collect;
	int	exit;
}	t_map;

/* open map */
void	open_map(int fd, t_map *info);

/* check map */
int	check_long_wall(char *str);
int	check_short_wall(char *str);
int	check_obj(char *str, t_map *info);

/* src */
void	ft_error(int e);


#endif