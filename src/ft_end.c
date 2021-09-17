/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:05:53 by swang             #+#    #+#             */
/*   Updated: 2021/09/18 01:17:18 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(int i)
{
	if (i == NO_PRAM)
		write(1, "no pram\n", 8);
	else if (i == FD_ERROR)
		write(1, "fd error\n", 9);
	else if (i == IMG_ERROR)
		write(1, "failed to road image\n", 21);
	else if (i == MLX_FAIL)
		write(1, "failed to conect window\n", 24);
	else if (i == NOT_SQUARE)
		write(1, "Map is not square\n", 18);
	write(2, "Error\n", 7);
	exit(0);
}

void	ft_goal(int i)
{
	write(1, "movement:", 10);
	write(1, &i, 1);
	write(1, "\n", 2);
	exit(0);
}

void	ft_die(int i)
{
	write(1, "you died\n", 10);
	write(1, &i, 1);
	exit(0);
}
