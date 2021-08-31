/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:14:35 by swang             #+#    #+#             */
/*   Updated: 2021/08/31 17:08:46 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(int e)
{
	if (e == MAP_ERROR)
	{
		write(2, "Error\n", 6);
		write(1, "The map must be composed of only 5 possible characters\n", 55);
	}
	else if (e == MAP_WALL_ERROR)
	{
		write(2, "Error\n", 6);
		write(1,"The map must be closed/surrounded by walls\n", 43);
	}
	else
	{
		write(2, "Error\n", 6);
	}
}