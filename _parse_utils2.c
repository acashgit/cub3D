/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:14:11 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/13 19:14:12 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_get_map(char *lines, t_env *env)
{
	char	**map;
	int		i;
	char	*tmp;

	i = 0;
	while (lines[i] && lines[i] == '\n')
		i++;
	if (!lines[i])
		ft_err_spl(env, "no map");
	tmp = ft_substr(&lines[i], 0, ft_strlen(&lines[i]));
	if (!tmp || !ft_addstr_mem(env, tmp, NULL))
		ft_err_spl(env, "failed to allocate memory");
	map = ft_split(tmp, 'q');
	if (!map)
		ft_err_spl(env, "failed to allocate memory");
	return (map);
}

char	**ft_getall(char *lines, t_env *env)
{
	int	len;
	int	maplen;

	len = ft_strlen(lines);
	while (len >= 0 && lines[len] != ',')
		len--;
	if (len == 0)
		ft_err_spl(env, "no instructions");
	while (lines[len] && lines[len] != '\n')
		len++;
	if (!lines[len] || !lines[len + 1])
		ft_err_spl(env, "no map");
	ft_get_instr(lines, len, env);
	maplen = ft_maplen(&lines[len + 1]);
	return (ft_get_map(&lines[len + 1], env));
}

int	ft_size_lines(char *lines)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (lines[i])
	{
		if (lines[i] == '\t')
			count += 4;
		else
			count++;
		i++;
	}
	return (count);
}

char	*ft_del_tabs(char *lines, t_env *env)
{
	int		size;
	char	*res;
	int		i;
	int		acc;

	size = ft_size_lines(lines);
	res = ft_malloc(1, size + 1, env);
	if (!res)
		ft_err_spl(env, "failed to allocate memory");
	res[size] = '\0';
	i = 0;
	size = 0;
	while (lines[i])
	{
		acc = 0;
		if (lines[i] == '\t')
		{
			while (acc++ < 4)
				res[size++] = ' ';
			i++;
		}
		else
			res[size++] = lines[i++];
	}
	return (res);
}
