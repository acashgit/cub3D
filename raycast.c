/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:36:29 by acash             #+#    #+#             */
/*   Updated: 2022/02/15 14:31:26 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_getray(t_env *env, int i, double len, double tmp)
{
	env->mr[i].w_type = env->map.map[(int)(env->mr[i].ye)] \
	[(int)(env->mr[i].xe)];
	env->mr[i].dirr = tmp;
	env->mr[i].len = len;
}

int	ft_get_index(t_env *env, int i, int j)
{
	if (env->mr[i].w_type == 'N' || env->mr[i].w_type == 'S')
	{
		if (env->mr[i].w_type == 'N')
			return (env->textures[0].addr[j * 32 + (int)env->mr[i].xe % 32]);
		else
			return (env->textures[1].addr[j * 32 + (int)env->mr[i].xe % 32]);
	}
	else
	{
		if (env->mr[i].w_type == 'W')
			return (env->textures[2].addr[j * 32 + (int)env->mr[i].ye % 32]);
		else
			return (env->textures[3].addr[j * 32 + (int)env->mr[i].ye % 32]);
	}
}

void	set_size(t_env *env, int i)
{
	int		acc;
	double	tmp;

	acc = 600;
	while (--acc > 0)
	{
		if (!((double)acc / 32.0 < (300.0 / 32.0 - (300.0 / 32.0 / \
			(env->mr[i].len / 40.0)))) && !((double)acc / 32.0 > \
			(300.0 / 32.0 + (300.0 / 32.0 / (env->mr[i].len / 40.0)))))
			env->mr[i].size++;
	}
	tmp = env->mr[i].size;
	env->mr[i].size = env->mr[i].size / 32.0 - 1;
	env->mr[i].size2 = (int)tmp % 32;
}

void	ft_ray(t_env *env)
{
	int		i;
	double	tmp;
	double	len;

	i = 0;
	tmp = env->plr.start;
	while (i < 800)
	{
		len = 0;
		env->mr[i].xe = env->plr.x;
		env->mr[i].ye = env->plr.y;
		while (env->map.map[(int)floor(env->mr[i].ye)] \
		[(int)floor(env->mr[i].xe)] == '0')
		{
			env->mr[i].xe += cos(tmp);
			env->mr[i].ye -= sin(tmp);
			len++;
		}
		ft_getray(env, i, len, tmp);
		set_size(env, i);
		tmp += 0.0011;
		i++;
	}
}
