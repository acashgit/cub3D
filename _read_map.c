/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:21:08 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/13 19:21:08 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_read(char *file)
{
	int		fd;
	char	tmp[BUFFER_SIZE + 1];
	char	*curr;
	int		ret;

	fd = open(file, O_RDONLY);
	ret = 1;
	curr = NULL;
	while (ret)
	{
		ret = read(fd, tmp, BUFFER_SIZE);
		if (ret < 0)
		{
			free(curr);
			return (NULL);
		}
		tmp[ret] = '\0';
		curr = ft_strjoin_gnl(curr, tmp);
		if (!curr)
		{
			free(curr);
			return (NULL);
		}
	}
	return (curr);
}

char	*ft_strdup64(char *str)
{
	int		i;
	char	*res;
	int		z;

	i = 0;
	res = ft_calloc(ft_strlen(str) * 32 + 1, 1);
	while (str[i])
	{
		z = 0;
		while (z < 32)
		{
			res[i * 32 + z] = str[i];
			z++;
		}
		i++;
	}
	free(str);
	return (res);
}

void	ft_zoom_maximum(t_env *env)
{
	int		i;
	char	**tmp_map;
	int		z;

	i = 0;
	while (env->map.map[i])
		i++;
	tmp_map = malloc(sizeof(char *) * 32 * i + sizeof(char *));
	tmp_map[32 * i] = NULL;
	z = 0;
	i = -1;
	while (env->map.map[++i])
	{
		z = -1;
		while (++z < 32)
			tmp_map[i * 32 + z] = ft_strdup(env->map.map[i]);
	}
	i = -1;
	while (tmp_map[++i])
		tmp_map[i] = ft_strdup64(tmp_map[i]);
	ft_myfree(env->map.map);
	env->map.map = tmp_map;
}

void	ft_fill_units(t_env *env)
{
	int		y;
	int		x;

	y = -1;
	while (env->map.map[++y])
	{
		x = -1;
		while (env->map.map[y][++x])
			if (env->map.map[y][x] == ' ')
				env->map.map[y][x] = '1';
	}
}

void	ft_get_instr_map(t_env *env, char *file)
{
	char	*line;

	check_map_name(env, file);
	line = ft_read(file);
	if (!line || !ft_addstr_mem(env, line, NULL))
		ft_err_spl(env, "Wrong map path");
	line = ft_del_tabs(line, env);
	env->map.map = ft_getall(line, env);
	ft_check_map(env);
	ft_fill_units(env);
	ft_zoom_maximum(env);
	ft_get_oriented(env);
}
