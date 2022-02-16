/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _get_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:13:50 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/13 19:13:51 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_lenval(t_env *env, char *rgb)
{
	int	i;
	int	acc;

	if (!rgb[0])
		ft_err_spl(env, "bad instruction");
	i = -1;
	acc = 1;
	while (rgb[++i] && (ft_isdigit(rgb[i]) || rgb[i] == ','))
		if (rgb[i] == ',')
			acc++;
	if (acc != 3)
		ft_err_spl(env, "bad instruction");
	while (rgb[i] && rgb[i] != '\n')
	{
		if (rgb[i] != ' ')
			ft_err_spl(env, "bad instruction");
		i++;
	}		
}

int	ft_get_num(char *tmp, int *field)
{
	char	*num;
	int		len;

	len = 0;
	while (tmp[len] && (tmp[len] != ',' && tmp[len] != ' '))
		len++;
	num = ft_substr(tmp, 0, len);
	*field = ft_atoi(num);
	free(num);
	return (len + 1);
}

void	ft_set_f_c(t_env *env)
{
	env->map.dwn = (env->map.floor.r << 16 \
	| env->map.floor.g << 8 | env->map.floor.b);
	env->map.up = (env->map.ceil.r << 16 \
	| env->map.ceil.g << 8 | env->map.ceil.b);
}

void	ft_get_floor(t_env *env, char *tmp)
{
	int		i;

	i = 0;
	if (!tmp)
		ft_err_spl(env, "Wrong instruction");
	while (tmp[i] && !ft_isdigit(tmp[i]))
		i++;
	ft_check_lenval(env, &tmp[i]);
	i += ft_get_num(&tmp[i], &(env->map.floor.r));
	i += ft_get_num(&tmp[i], &(env->map.floor.g));
	i += ft_get_num(&tmp[i], &(env->map.floor.b));
}

void	ft_get_ceiling(t_env *env, char *tmp)
{
	int		i;

	i = 0;
	if (!tmp)
		ft_err_spl(env, "no such instruction");
	while (tmp[i] && !ft_isdigit(tmp[i]))
		i++;
	ft_check_lenval(env, &tmp[i]);
	i += ft_get_num(&tmp[i], &(env->map.ceil.r));
	i += ft_get_num(&tmp[i], &(env->map.ceil.g));
	i += ft_get_num(&tmp[i], &(env->map.ceil.b));
}
