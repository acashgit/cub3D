/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_map1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:10:06 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/13 19:42:48 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_checkduplicate(t_env *env, char *instr, int index)
{
	char	*tmp;

	tmp = ft_strnstr(instr, "NO ", index);
	if (!tmp || ft_strnstr(tmp + 2, "NO ", ft_strlen(tmp)))
		ft_err_spl(env, "duplicate NO");
	tmp = ft_strnstr(instr, "SO ", index);
	if (!tmp || ft_strnstr(tmp + 2, "SO ", ft_strlen(tmp)))
		ft_err_spl(env, "duplicate SO");
	tmp = ft_strnstr(instr, "WE ", index);
	if (!tmp || ft_strnstr(tmp + 2, "WE ", ft_strlen(tmp)))
		ft_err_spl(env, "duplicate WE");
	tmp = ft_strnstr(instr, "EA ", index);
	if (!tmp || ft_strnstr(tmp + 2, "EA ", ft_strlen(tmp)))
		ft_err_spl(env, "duplicate EA");
	tmp = ft_strnstr(instr, "C ", index);
	if (!tmp || ft_strnstr(tmp + 1, "C ", ft_strlen(tmp)))
		ft_err_spl(env, "duplicate C");
	tmp = ft_strnstr(instr, "F ", index);
	if (!tmp || ft_strnstr(tmp + 1, "F ", ft_strlen(tmp)))
		ft_err_spl(env, "duplicate F");
}

void	ft_check_file(t_env *env)
{
	int	fd;

	fd = open(env->map.ea, O_RDONLY);
	if (fd == -1)
		ft_err_spl(env, "no such file EA");
	close(fd);
	fd = open(env->map.no, O_RDONLY);
	if (fd == -1)
		ft_err_spl(env, "no such file NO");
	close(fd);
	fd = open(env->map.so, O_RDONLY);
	if (fd == -1)
		ft_err_spl(env, "no such file SO");
	close(fd);
	fd = open(env->map.we, O_RDONLY);
	if (fd == -1)
		ft_err_spl(env, "no such file WE");
	close(fd);
}

char	*ft_check_path(char *tmp, t_env *env)
{
	int		i;
	int		len;
	char	*res1;

	i = 2;
	while (tmp[i] == ' ')
		i++;
	if (!tmp[i] || tmp[i] == '\n')
		ft_err_spl(env, "Wrong instruction");
	len = i;
	while (tmp[len] && tmp[len] != '\n')
		len++;
	if (!tmp[len])
		ft_err_spl(env, "no map");
	res1 = ft_substr(tmp, i, len - i);
	if (!res1 || !ft_addstr_mem(env, res1, NULL))
		ft_err_spl(env, "failed to allocate memory");
	return (ft_strtrim(res1, " "));
}

void	ft_check_simbols(t_env *env)
{
	int	x;
	int	y;
	int	count_p;

	y = -1;
	count_p = 0;
	while (env->map.map[++y])
	{
		x = -1;
		while (env->map.map[y][++x])
		{
			if (env->map.map[y][x] == 'N' || env->map.map[y][x] == 'S' \
			|| env->map.map[y][x] == 'W' || env->map.map[y][x] == 'E')
				ft_set_inform(env, x, y, &count_p);
			else if (env->map.map[y][x] != '0' && env->map.map[y][x] != '1' \
			&& env->map.map[y][x] != '\n' && env->map.map[y][x] != ' ')
				ft_err_spl(env, "forbidden characters");
		}
	}
	if (count_p > 1)
		ft_err_spl(env, "many players");
	if (count_p < 1)
		ft_err_spl(env, "not enough players");
}

void	ft_check_map(t_env *env)
{
	get_modif_map(env);
	ft_check_simbols(env);
	ft_check_left_side(env);
	ft_check_right_side(env);
	ft_check_up(env);
	ft_check_down(env);
}
