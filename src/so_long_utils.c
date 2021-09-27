/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:05:15 by swang             #+#    #+#             */
/*   Updated: 2021/09/28 06:03:08 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	join_len;
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	join_len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (join_len + 1));
	if (!join)
		return (NULL);
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;
	char	*new;

	len = ft_strlen(s1);
	str = (char *)s1;
	new = ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (len--)
		new[len] = str[len];
	return (new);
}

void	ft_shell_out(int move)
{
	char	*ptr;

	ptr = ft_itoa(move);
	write(1, "movement:", 9);
	write(1, ptr, ft_strlen(ptr));
	write(1, "\n", 1);
	free(ptr);
	ptr = 0;
}
