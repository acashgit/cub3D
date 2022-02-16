/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:55:19 by acash             #+#    #+#             */
/*   Updated: 2022/02/13 19:56:41 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	end_hook(t_env *env)
{
	(void)env;
	ft_free_all_alloc(env);
	exit(0);
	return (0);
}

int	check_wall2(t_env *env, double dir)
{
	double	x;
	double	y;
	int		i;

	i = 0;
	x = env->plr.x;
	y = env->plr.y;
	while (i < 10)
	{
		x -= cos(dir) * 1;
		if (env->map.map[(int)(y)][(int)(x)] != '0')
			return (0);
		y += sin(dir) * 1;
		if (env->map.map[(int)(y)][(int)(x)] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(t_env *env, double dir, int code)
{
	double	x;
	double	y;
	int		i;

	i = 0;
	x = env->plr.x;
	y = env->plr.y;
	if (code != -1)
		return (check_wall2(env, dir));
	else
	{
		while (i < 10)
		{
			x += cos(dir) * 1;
			if (env->map.map[(int)(y)][(int)(x)] != '0')
				return (0);
			y -= sin(dir) * 1;
			if (env->map.map[(int)(y)][(int)(x)] != '0')
				return (0);
			i++;
		}
	}
	return (1);
}
