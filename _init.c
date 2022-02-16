/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:13:15 by acash             #+#    #+#             */
/*   Updated: 2022/02/13 17:21:54 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initmr(t_env *env)
{
	int	i;

	i = 0;
	env->mr = malloc(sizeof(t_ray) * 801);
	if (!env->mr)
		ft_error();
	while (i < 800)
	{
		env->mr[i].len = 0;
		env->mr[i].dirr = 0;
		env->mr[i].xe = 0;
		env->mr[i].ye = 0;
		env->mr[i].w_type = '0';
		env->mr[i].size = 0;
		env->mr[i].flag = 0;
		i++;
	}
	env->tmp = 800;
}

void	ft_helpdir(t_env *env)
{
	if (env->map.player == 'W')
	{
		env->plr.dir = 3.138;
		env->plr.start = 2.764;
		env->plr.end = 3.472;
		env->plr.rdir = -1.579;
	}
	if (env->map.player == 'E')
	{
		env->plr.dir = 0;
		env->plr.start = -0.354;
		env->plr.end = 0.354;
		env->plr.rdir = 1.579;
	}
}

void	ft_initdir(t_env *env)
{
	if (env->map.player == 'N')
	{
		env->plr.dir = 1.589;
		env->plr.start = 1.225;
		env->plr.end = 1.95;
		env->plr.rdir = 3.118;
	}
	if (env->map.player == 'S')
	{
		env->plr.dir = -1.559;
		env->plr.start = -1.95;
		env->plr.end = -1.225;
		env->plr.rdir = 0;
	}
	ft_helpdir(env);
}

int	ft_init(t_env *env)
{
	env->mem.alloc_for_split = NULL;
	env->mem.alloc_mem = NULL;
	env->mlx = NULL;
	env->win = NULL;
	env->plr.dir = 1.574;
	env->plr.start = 1;
	env->plr.end = 2.1;
	env->plr.rdir = 3.118;
	env->plr.x = 0;
	env->plr.y = 0;
	env->vz = 0;
	env->vz_prev = 0;
	env->map.map = NULL;
	env->map.we = NULL;
	env->map.so = NULL;
	env->map.ea = NULL;
	env->map.no = NULL;
	env->vz = 0;
	env->map.player = 'N';
	ft_initmr(env);
	return (1);
}

void	ft_raycast_init(t_env *env)
{
	env->textures[0].img = mlx_xpm_file_to_image(env->mlx, \
	env->map.no, &env->textures[0].width, &env->textures[0].height);
	env->textures[1].img = mlx_xpm_file_to_image(env->mlx, \
	env->map.so, &env->textures[1].width, &env->textures[1].height);
	env->textures[2].img = mlx_xpm_file_to_image(env->mlx, \
	env->map.we, &env->textures[2].width, &env->textures[2].height);
	env->textures[3].img = mlx_xpm_file_to_image(env->mlx, \
	env->map.ea, &env->textures[3].width, &env->textures[3].height);
	env->textures[0].addr = (int *)mlx_get_data_addr(env->textures[0].img, \
	&env->textures[0].bpp,
			&env->textures[0].size_l, &env->textures[0].endian);
	env->textures[1].addr = (int *)mlx_get_data_addr(env->textures[1].img, \
	&env->textures[1].bpp,
			&env->textures[1].size_l, &env->textures[1].endian);
	env->textures[2].addr = (int *)mlx_get_data_addr(env->textures[2].img, \
	&env->textures[2].bpp,
			&env->textures[2].size_l, &env->textures[2].endian);
	env->textures[3].addr = (int *)mlx_get_data_addr(env->textures[3].img, \
	&env->textures[3].bpp,
			&env->textures[3].size_l, &env->textures[3].endian);
}
