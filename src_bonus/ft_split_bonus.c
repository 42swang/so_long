/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:09:31 by swang             #+#    #+#             */
/*   Updated: 2021/09/19 20:34:12 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static char	**ft_free(char **res, int res_i)
{
	while (res_i >= 0)
	{
		free(res[res_i]);
		res[res_i] = 0;
		res_i--;
	}
	free(res);
	res = 0;
	return (NULL);
}

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static char	**ft_make_res(char const *s, char c, char **res, int c_word)
{
	int	i;
	int	start;
	int	end;
	int	res_i;

	i = 0;
	start = 0;
	end = 0;
	res_i = 0;
	while (res_i < c_word && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i - 1;
		res[res_i] = ft_substr(s, (unsigned int)start,
				(int)(end - start + 1));
		if (!res[res_i])
			return (ft_free(res, res_i));
		res_i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		c_word;

	if (s == 0)
		return (NULL);
	c_word = ft_count_word(s, c);
	res = ft_calloc((size_t)c_word + 1, sizeof(char *));
	if (!res)
		return (NULL);
	res = ft_make_res(s, c, res, c_word);
	return (res);
}
