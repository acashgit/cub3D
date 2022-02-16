/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:49 by acash             #+#    #+#             */
/*   Updated: 2022/02/13 17:37:47 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(t_env *env, int code)
{
	if (code == -1 && check_wall(env, env->plr.dir, code))
	{
		env->plr.x += cos(env->plr.dir) * 4;
		env->plr.y -= sin(env->plr.dir) * 4;
	}
	if (code == 1 && check_wall(env, env->plr.dir, code))
	{
		env->plr.x -= cos(env->plr.dir) * 4;
		env->plr.y += sin(env->plr.dir) * 4;
	}
}

void	ft_strafe(t_env *env, int code)
{
	if (code == -1 && check_wall(env, env->plr.rdir, code))
	{
		env->plr.x += cos(env->plr.rdir) * 4;
		env->plr.y -= sin(env->plr.rdir) * 4;
	}
	if (code == 1 && check_wall(env, env->plr.rdir, code))
	{
		env->plr.x -= cos(env->plr.rdir) * 4;
		env->plr.y += sin(env->plr.rdir) * 4;
	}
}

void	ft_rotate(t_env *env, int code)
{
	if (code == 1)
	{
		env->plr.dir -= 0.1;
		env->plr.start -= 0.1;
		env->plr.end -= 0.1;
		env->plr.rdir -= 0.1;
	}
	if (code == -1)
	{
		env->plr.dir += 0.1;
		env->plr.start += 0.1;
		env->plr.end += 0.1;
		env->plr.rdir += 0.1;
	}
}

int	keyb_hook(int key, t_env *env)
{
	if (key == W)
		ft_move(env, -1);
	if (key == S)
		ft_move(env, 1);
	if (key == A)
		ft_strafe(env, -1);
	if (key == D)
		ft_strafe(env, 1);
	if (key == LEFT)
		ft_rotate(env, -1);
	if (key == RIGHT)
		ft_rotate(env, 1);
	if (key == ESC)
		exit(0);
	ft_ray(env);
	return (0);
}
