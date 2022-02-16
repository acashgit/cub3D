/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:11:58 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/13 19:41:13 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_inform(t_env *env, int x, int y, int *count_p)
{
	env->map.player = env->map.map[y][x];
	env->plr.x = x;
	env->plr.y = y;
	env->map.map[y][x] = '0';
	(*count_p)++;
}

void	ft_edit_field(t_env *env, char *tmp, char **field)
{
	if (!tmp)
		ft_err_spl(env, "Wrong instruction");
	*field = ft_check_path(tmp, env);
	if (!(*field) || !ft_addstr_mem(env, *field, NULL))
		ft_err_spl(env, "failed to allocate memory");
}

void	ft_get_instr(char *lines, int index, t_env *env)
{
	int		i;
	char	*instr;
	char	*tmp;

	i = 0;
	instr = ft_substr(lines, 0, index);
	if (!instr || !ft_addstr_mem(env, instr, NULL))
		ft_err_spl(env, "failed to allocate memory");
	tmp = ft_strnstr(instr, "NO ", index);
	ft_edit_field(env, tmp, &(env->map.no));
	tmp = ft_strnstr(instr, "SO ", index);
	ft_edit_field(env, tmp, &(env->map.so));
	tmp = ft_strnstr(instr, "WE ", index);
	ft_edit_field(env, tmp, &(env->map.we));
	tmp = ft_strnstr(instr, "EA ", index);
	ft_edit_field(env, tmp, &(env->map.ea));
	ft_checkduplicate(env, instr, index);
	tmp = ft_strnstr(instr, "F ", index);
	ft_get_floor(env, tmp);
	ft_checkduplicate(env, instr, index);
	tmp = ft_strnstr(instr, "C ", index);
	ft_get_ceiling(env, tmp);
	ft_checkduplicate(env, instr, index);
	ft_set_f_c(env);
	ft_check_file(env);
}
