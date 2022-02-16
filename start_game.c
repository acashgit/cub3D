/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:19:46 by acash             #+#    #+#             */
/*   Updated: 2022/02/13 20:17:23 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//duplicate instr
void	ft_putplayermp(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mlx_pixel_put(env->mlx, env->win, (env->plr.x / 4) + i, \
			(env->plr.y / 4) + j, 0X000000);
			j++;
		}
		i++;
	}
}

void	ft_draw_wall(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (env->map.map[i])
	{
		j = 0;
		while (env->map.map[i][j])
		{
			if (env->map.map[i][j] == 'W')
				mlx_pixel_put(env->mlx, env->win, (j / 4), (i / 4), 0XFF0066);
			if (env->map.map[i][j] == 'S')
				mlx_pixel_put(env->mlx, env->win, (j / 4), (i / 4), 0X3300FF);
			if (env->map.map[i][j] == 'N')
				mlx_pixel_put(env->mlx, env->win, (j / 4), (i / 4), 0XCC00CC);
			if (env->map.map[i][j] == 'E')
				mlx_pixel_put(env->mlx, env->win, (j / 4), (i / 4), 0XFFFF00);
			j++;
		}
		i++;
	}
	ft_putplayermp(env);
}

void	start_game(t_env *env)
{
	env->mlx = mlx_init();
	env->data.img = mlx_new_image(env->mlx, 800, 600);
	env->data.addr = (int *)mlx_get_data_addr(env->data.img, &env-> \
			data.bpp, &env->data.size_l, &env->data.endian);
	env->win = mlx_new_window(env->mlx, 800, 600, "cub3d");
	ft_raycast_init(env);
	ft_ray(env);
	mlx_loop_hook(env->mlx, ft_raycasting, env);
	mlx_hook(env->win, 2, 0, keyb_hook, env);
	mlx_hook(env->win, 17, 0, end_hook, env);
	mlx_loop(env->mlx);
}
