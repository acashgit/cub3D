/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _raycasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:55:42 by acash             #+#    #+#             */
/*   Updated: 2022/02/15 14:19:57 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_deep(t_env *env, int i)
{
	int	acc;

	acc = 600;
	while (--acc > 0)
	{
		if ((double)acc / 32.0 < (300.0 / 32.0 - \
			(300.0 / 32.0 / (env->mr[i].len / 40.0))))
			env->data.addr[(acc) * 800 - i] = (env->map.up);
		else if ((double)acc / 32.0 > (300.0 / 32.0 + \
			(300.0 / 32.0 / ((env->mr[i].len / 40.0)))))
			env->data.addr[(acc) * 800 - i] = (env->map.dwn);
	}
}

int	ft_pixd(t_env *e, int i, int flag)
{
	double	z;

	z = 0;
	while (e->a > 0 && z < e->mr[i].size)
	{
		flag = 1;
		e->data.addr[(e->a) * 800 - i] = ft_get_index(e, i, (e->vz) % 32);
		e->a--;
		z++;
	}
	e->vz++;
	if (!flag)
		e->a--;
	return (flag);
}

void	draw_col(t_env *e, int i)
{
	int	flag;

	e->a = 599;
	e->vz = 0;
	while (e->a > 0)
	{
		flag = 0;
		if ((double)e->a / 32.0 < (300.0 / 32.0 - \
		(300.0 / 32.0 / ((e->mr[i].len) / 40.0))))
		{
			e->data.addr[(e->a) * 800 - i] = (e->map.up);
			e->a--;
		}
		else if ((double)e->a / 32.0 > (300.0 / 32.0 + \
		(300.0 / 32.0 / ((e->mr[i].len / 40.0)))))
		{
			e->data.addr[(e->a) * 800 - i] = (e->map.dwn);
			e->a--;
		}
		else
			flag = ft_pixd(e, i, flag);
	}
	draw_deep(e, i);
}

int	ft_raycasting(t_env *env)
{
	int	i;

	i = -1;
	mlx_clear_window(env->mlx, env->win);
	i = 0;
	while (i < 800)
		draw_col(env, i++);
	i = -1;
	while (++i < 800)
		env->mr[i].size = 0;
	mlx_put_image_to_window(env->mlx, env->win,
		env->data.img, 0, 0);
	ft_draw_wall(env);
	return (1);
}
