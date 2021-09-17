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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}

void	ft_error(int i)
{
	/*if (i == NO_PRAM)
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
	*/
	if (i < 0)
		printf("1\n");
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