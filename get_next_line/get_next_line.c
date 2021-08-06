/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:17:36 by swang             #+#    #+#             */
/*   Updated: 2021/03/29 18:26:30 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	split_save(char **line, char **save)
{
	char	*nl_ptr;
	char	*temp;

	nl_ptr = ft_strnl(*save);
	temp = *line;
	*line = ft_substr(*save, 0, nl_ptr - *save);
	if (!(*line))
		return (-1);
	free(temp);
	temp = *save;
	*save = ft_substr(nl_ptr + 1, 0, ft_strlen(nl_ptr + 1));
	if (!(*save))
		return (-1);
	free(temp);
	temp = 0;
	return (1);
}

int	read_file(int fd, char **line, char **save)
{
	ssize_t	read_size;
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	int		ret;

	ret = 42;
	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size > 0)
	{
		buf[read_size] = '\0';
		temp = ft_strjoin(*save, buf);
		if (!temp)
			return (-1);
		free(*save);
		*save = temp;
		if (ft_strnl(*save) != 0)
			ret = split_save(line, save);
		else
			ret = 2;
	}
	else if (read_size == 0)
		ret = 3;
	else
		ret = -1;
	return (ret);
}

int	read_more(int fd, char **line, char **save)
{
	int		ret;
	char	*temp;

	if (*save == 0)
		*save = ft_strdup("");
	if (!(*save))
		return (-1);
	ret = 2;
	while (ret == 2)
		ret = read_file(fd, line, save);
	if (ret == -1 || ret == 1)
		return (ret);
	if (ret == 3)
	{
		temp = *line;
		*line = *save;
		*save = 0;
		free(temp);
		temp = 0;
		ret = 0;
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || fd > OPEN_MAX)
		return (-1);
	*line = ft_strdup("");
	if (!(*line))
		return (-1);
	ret = 2;
	if (save[fd] != 0 && ft_strnl(save[fd]) != 0)
		ret = split_save(line, &save[fd]);
	else
		ret = read_more(fd, line, &save[fd]);
	if (ret == -1)
	{
		if (save[fd] != 0)
			free(save[fd]);
		save[fd] = 0;
	}
	return (ret);
}
