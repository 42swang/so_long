#include "../include/so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_error(int i)
{
	if (i == NO_PRAM)
		write(1, "no pram\n", 8);
	else if (i == FD_ERROR)
		write(1, "fd error\n", 9);
	else if (i == MAP_ERROR)
		write(1, "MAP don't fill\n", 15);
	else if (i == IMG_ERROR)
		write(1, "failed to road image\n", 21);
	else if (i == MLX_FAIL)
		write(1, "failed to conect window\n", 24);
	else if (i == NOT_SQUARE)
		write(1, "Map is not square\n", 18);
	write(2, "Error\n", 6);
	exit(0);
}