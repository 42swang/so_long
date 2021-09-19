/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:05:53 by swang             #+#    #+#             */
/*   Updated: 2021/09/19 21:01:35 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

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

void	ft_goal(int move)
{
	char	*ptr;

	ptr = ft_itoa(move);
	write(1, "movement :", 10);
	write(1, ptr, ft_strlen(ptr));
	write(1, "\n", 1);
	write(1, "Good\n", 5);
	exit(0);
}

void	ft_die(int move)
{
	char	*ptr;

	ptr = ft_itoa(move);
	write(1, "movement :", 10);
	write(1, ptr, ft_strlen(ptr));
	write(1, "\n", 1);
	write(1, "You Died\n", 9);
	exit(0);
}